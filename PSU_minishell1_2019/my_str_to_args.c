/*
** EPITECH PROJECT, 2020
** my_str_to_args
** File description:
** str to args
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"

static int strlen;
static int argc;

int check_quote_error(char *str)
{
    int d_quote = 0;
    int s_quote = 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"' && s_quote % 2 != 1)
            d_quote++;
        if (str[i] == 39 && d_quote % 2 != 1)
            s_quote++;
    }
    if (d_quote % 2 == 1 || s_quote % 2 == 1)
        return (1);
    return (0);
}

int parse_str(char *str)
{
    int dquote = 0;
    int squote = 0;

    if (check_quote_error(str))
        return (-1);
    for (int i = 0; i < strlen; i++) {
        if (str[i] == '\\') {
            i++;
            continue;
        }
        if (str[i] == '"') dquote++;
        if (str[i] == '\'') squote++;
        if (dquote % 2 == 1 || squote % 2 == 1) continue;
        if (i > 0 && (str[i] == ' ' || str[i] == '\t')
            && (str[i-1] != ' ' && str[i-1] != '\t' && str[i-1] != '\0'))
            str[i] = '\0';
    }
}

int count_arg(char *str)
{
    int argc = 0;

    for (int i = 0; i < strlen+1; i++)
        if (str[i] == '\0' && str[i - 1] != ' ' && str[i - 1] != '\0')
            argc++;
    return (argc);
}

void get_args(char **argv, char *str, int argc)
{
    int len = 0;
    int arg_i;
    int index = 0;

    argv[argc] = NULL;
    for (int i = 0; i < argc; i++) {
        while (*str == ' ' || *str == '\t')
            str = str + 1;
        len = my_strlen(str);
        argv[i] = my_strdup(str);
        str = str + (len + 1);
    }
}

char **my_str_to_args_array(char *str)
{
    char **argv;
    int strstatus = 0;
    strlen = my_strlen(str);
    if (strlen == 0)
        return (NULL);
    strstatus = parse_str(str);
    if (strstatus == -1)
        return (NULL);
    argc = count_arg(str);
    if (argc == 0)
        return (NULL);
    argv = malloc(sizeof(char *) * (argc + 1));
    get_args(argv, str, argc);
    return (argv);
}
