/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_get_nbr fictive
*/

#include "my.h"
#include <stdlib.h>

char *get_number(char *str, int i, char **endptr, int is_neg)
{
    int n = 0;
    while ((str[i] >= '0' && str[i] <= '9')) {
        i++;
    }
    char *num = malloc(i + 1);
    my_strncpy(num, str, i);
    num[i] = '\0';
    if (endptr != 0)
        *endptr = *endptr + i;
    return (num);
}

char *my_strtol(char *str, char **endptr)
{
    int i = 0;
    int is_neg = 1;
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            is_neg = is_neg * -1;
        }
        i++;
    }
    return (get_number(str, i, endptr, is_neg));
}
