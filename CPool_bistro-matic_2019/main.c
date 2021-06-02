/*
** EPITECH PROJECT, 2019
** main file for bistro
** File description:
** bistro main file
*/
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "bistromatic.h"
#include "my.h"
#include "eval.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses");
    my_putstr(" and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    exit(EXIT_USAGE);
}

int bistro_matic(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *str;
    char *result;

    if (ac != 4 || (ac > 2 && my_strcmp(av[1], "-h") == 0)){
        usage();
        return (84);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    if (error(ac, expr, av, size) != 0)
        return (84);
    str = convert_bistro(expr, av[1], av[2]);
    result = eval_expr(str);
    my_putstr(convert_end(result, av[1], av[2]));
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    int res;
    res = bistro_matic(ac, av);
    return (res);
}
