/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** error handling
*/

#include "my.h"
#include "error.h"
#include "bistromatic.h"
#include <stdlib.h>
#include <stdio.h>

int find_char(char op, char *num, char *sign)
{
    for (int a = 0; num[a] != '\0'; a++) {
        if (op == num[a])
            return (0);
    }
    for (int a = 0; sign[a] != '\0'; a++) {
        if (op == sign[a])
            return (0);
    }
    return (84);
}

int find_db_char(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        for (int b = a + 1; str[b] != '\0'; b++) {
            if (str[a] == str[b])
                return (84);
        }
    }
    return (0);
}

void base_check(char *num, char *sign)
{
    for (int a = 0; num[a] != '\0'; a++) {
        if (find_num(num[a], sign) == 0
            || find_db_char(num) == 84) {
            my_put_error(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
    if (find_db_char(sign) == 84) {
        my_put_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int op_check(char *op, char *num, char *sign, int size)
{
    int ret;

    for (int a = 0; a < size; a++) {
        ret = find_char(op[a], num, sign);
        if (ret == 84) {
            my_put_error(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
    return (0);
}
