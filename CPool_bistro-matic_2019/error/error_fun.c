/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** error handling
*/

#include "error.h"
#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int find_num(char op, char *num)
{
    for (int a = 0; num[a] != '\0'; a++) {
        if (op == num[a])
            return (0);
    }
    return (84);
}

void par_num(char *num, char *op, int size)
{
    for (int a = 1; a < size - 1; a++) {
        if (op[a] == ')' && find_num(op[a + 1], num) == 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
        if (op[a] == '(' && find_num(op[a - 1], num) == 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
    }
}

void sign_follow(char *op, char *sign, char *num, int size)
{
    for (int a = 1; a < size - 1; a++) {
        if ((op[a] == '*' || op[a] == '/') &&
            (op[a - 1] ==  '*' || op[a - 1] == '/'
            || op[a + 1] ==  '*' || op[a + 1] == '/')) {
            my_put_error(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        }
    }
}
