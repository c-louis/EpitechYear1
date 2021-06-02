/*
** EPITECH PROJECT, 2019
** sanitalize_str
** File description:
** sanitalize -> remove space
*/

#include "my.h"
#include "eval.h"
#include <stdio.h>

int my_strlen_without_space(char *str)
{
    int i = 0;
    while (str[i] != ' ' || str[i] != '\0')
        i++;
    return (i);
}

void replace_sani_str(char *str, int i)
{
    for (int y = i; str[y] != '\0'; y++) {
        if (str[y] != ' ') {
            str[i] = str[y];
            str[y] = ' ';
            break;
        }
    }
}

void check_multiple(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i + 1] == '+') {
            str[i + 1] = ' ';
            i++;
        }
        if (str[i] == '+' && str[i + 1] == '-') {
            str[i] = ' ';
            i++;
        }
        if (str[i] == '-' && str[i + 1] == '-') {
            str[i] = '+';
            str[i + 1] = ' ';
            i++;
        }
        if (str[i] == '+' && str[i + 1] == '+') {
            str[i] = '+';
            str[i + 1] = ' ';
            i++;
        }
    }
}

void sanitalize_str(char *str)
{
    check_multiple(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            replace_sani_str(str, i);
        }
    }
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            break;
        }
    }
}
