/*
** EPITECH PROJECT, 2019
** handle_file
** File description:
** all the handle function for all kind of things
*/

#include "my.h"
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>

void handle_parenthesis(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            int end = get_end_parenthesis(str, i);
            char *tmp_str = malloc(end - i + 1);
            my_strncpy(tmp_str, str+i+1, end-i-1);
            char *result = get_result(tmp_str);
            replace_by_result(str, i, end+1, result);
            i = 0;
        }
    }
}

void handle_factors(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '*' && str[i] != '/' && str[i] != '%') {
            continue;
        }
        int idx = get_start_index(str, i);
        int idxend = get_end_index(str, idx);
        char *tmp = str + idx;
        char *result = factors(&tmp);
        replace_by_result(str, idx, idxend, result);
        i = 0;
    }
}

void handle_summands(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '+' && str[i] != '-') {
            continue;
        }
        int idx = get_start_index(str, i);
        int idxend = get_end_index(str, idx);
        char *tmp = str + idx;
        char *result = summands(&tmp);
        replace_by_result(str, idx, idxend, result);
        i = 0;
    }
}
