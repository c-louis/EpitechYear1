/*
** EPITECH PROJECT, 2019
** do_op main file
** File description:
** do_operation
*/

#include <stddef.h>
#include "my.h"

char my_getoperator(char *str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        return (str[i]);
    if (str[i] == '%')
        return (str[i]);
    return (0);
}

int dispatch_calcul(int fnb, int snb, char operator)
{
    if (operator == '+')
        return (fnb + snb);
    if (operator == '*')
        return (fnb * snb);
    if (operator == '-')
        return (fnb - snb);
    if (operator == '%')
        return (fnb % snb);
    if (operator == '/') {
        if (snb > fnb)
            return (0);
        return (fnb / snb);
    }
    return (0);
}

void check_error(char operator)
{
    if (operator == 0)
        my_put_nbr(0);
    if (operator == '/')
        my_putstr("Stop: division by zero");
    if (operator == '%')
        my_putstr("Stop: modulo by zero");
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    if (argc == 4) {
        int fnb = my_getnbr(argv[1]);
        int snb = my_getnbr(argv[3]);
        char operator = my_getoperator(argv[2]);
        if ((operator == 0) || (operator == '/' && snb == 0)
            || (operator == '%' && snb == 0)) {
            check_error(operator);
            return (84);
        }
        int result = dispatch_calcul(fnb, snb, operator);
        my_put_nbr(result);
        my_putchar('\n');
        return (0); }
    return (84);
}
