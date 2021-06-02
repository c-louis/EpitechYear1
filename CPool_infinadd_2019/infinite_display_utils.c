/*
** EPITECH PROJECT, 2019
** display utils for infinite number
** File description:
** display function for infinite numbers
*/

#include "my.h"
#include "infinite.h"

void my_put_result(char *result, int is_neg)
{
    if (is_neg)
        my_putchar('-');
    while (*result == '0')
        result = result + 1;
    my_putstr(result);
    my_putchar('\n');
}

void handle_number(char **av, int is_neg, int is_add, int is_inv)
{
    if (is_add && av[1][0] == '-') {
        remove_minus(av);
        is_neg = 1;
    }
    if (is_add) {
        char *result = infinite_add(av);
        my_put_result(result, is_neg);
        return;
    }
    if (!is_add) {
        if (is_inv) {
            remove_minus(av);
            char *result = infinite_sub(av[2], av[1]);
            my_put_result(result, is_neg);
        }
        else {
            remove_minus(av);
            char *result = infinite_sub(av[1], av[2]);
            my_put_result(result, is_neg);
        }
    }
}
