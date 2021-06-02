/*
** EPITECH PROJECT, 2019
** Utils function for the eval expr
** File description:
** expr utility function !!!
*/

#include "my.h"
#include "eval.h"
#include <stdio.h>

char get_operator(char **endptr)
{
    while ((**endptr != '*' && **endptr != '-' &&
            **endptr != '+' && **endptr != '/' &&
            **endptr != '%' && **endptr != '\0')) {
        if (**endptr == '\0')
            break;
        *endptr = *endptr + 1;
    }
    char operator = **endptr;
    if (**endptr != '\0')
        *endptr = *endptr + 1;
    return (operator);
}

void replace_by_result(char *str, int start, int end, char *res)
{
    int j = 0;
    for (int i = start; i < end; i++) {
        if (j < my_strlen(res)) {
            str[i] = res[j++];
        }
        else {
            str[i] = ' ';
        }
    }
    sanitalize_str(str);
}

int get_start_index(char *str, int y)
{
    for (int i = y-1; i > 0; i--) {
        if (str[i] < '0' || str[i] > '9')
            return (i+1);
    }
    return (0);
}

int get_end_index(char *str, int y)
{
    int num_f = 0;
    if (str[y] == '-' || str[y] == '+')
        y++;
    int i = 0;
    for (i = y; num_f < 2; i++) {
        if ((str[i] < '0' || str[i] > '9')) {
            num_f++;
            if (str[i + 1] == '-' && num_f == 1) {
                i++;
            }
        }
    }
    return (i-1);
}
