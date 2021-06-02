/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** display error message on error output
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"
#include "error.h"

void sign_follow(char *op, char *sign, char *num, int size);

void my_put_error(char *str)
{
    write (2, str, my_strlen(str));
}

void check_par_bis(char *op, char *opbase, int size)
{
    for (int i = 0; i < size; i++) {
        if (op[i] == '(' && i > 0) {
            if (!(is_operator_base(op[i - 1], opbase))) {
                my_put_error(SYNTAX_ERROR_MSG);
                exit(EXIT_READ);
            }
        }
    }
}

int check_par(char *op, char *opbase, int size)
{
    int count = 0;

    for (int a = 0; a < size; a++) {
        if (op[a] == opbase[1]) {
            if (count == 0) {
                my_put_error(SYNTAX_ERROR_MSG);
                exit(EXIT_READ);
            }
            count--;
        }
        if (op[a] == opbase[0])
            count++;
    }
    if (count != 0) {
        my_put_error(SYNTAX_ERROR_MSG);
        exit(EXIT_READ);
    }
    check_par_bis(op, opbase, size);
    return (0);
}

void argc_nb(int ac)
{
    if (ac != 4) {
        my_put_error(ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

int error(int ac, char *operation, char **av, int size)
{
    int ret = 0;

    argc_nb(ac);
    base_check(av[1], av[2]);
    op_check(operation, av[1], av[2], size);
    sign_follow(operation, av[2], av[1], size);
    check_par(operation, av[2], size);
    return (0);
}
