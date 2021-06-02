/*
** EPITECH PROJECT, 2019
** main file for the eval expr
** File description:
** eval expr
*/

#include "my.h"
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>

int get_end_parenthesis(char *str, int i)
{
    int enter_cnt = 1;
    for (int y = i+1; str[y] != '\0'; y++) {
        if (str[y] == '(') {
            enter_cnt++;
        }
        if (str[y] == ')') {
            enter_cnt--;
        }
        if (enter_cnt == 0)
            return (y);
    }
    return (my_strlen(str));
}

char *get_result(char *str)
{
    handle_parenthesis(str);
    handle_factors(str);
    handle_summands(str);
    return (str);
}

char *eval_expr(char const *str)
{
    int length = my_strlen(str);
    char *new_str = malloc(length);
    my_strcpy(new_str, str);
    sanitalize_str(new_str);
    char *result = get_result(new_str);
    return (result);
}
