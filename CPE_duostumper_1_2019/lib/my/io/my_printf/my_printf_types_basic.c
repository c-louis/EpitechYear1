/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_types_basic
*/

#include "../../my.h"
#include <stdarg.h>
#include <stdlib.h>

void print_c(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void print_d(va_list arg)
{
    my_putnbr(va_arg(arg, int));
}

void print_s(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

void print_p(va_list arg)
{
    long int nb = va_arg(arg, long int);
    long int i = 0;
    long int remainder;
    long int tmp;
    char *letters = "0123456789abcdef";
    char *output = malloc(sizeof(char) * 100);

    while (nb != 0) {
        tmp = nb;
        nb /= 16;
        remainder = tmp % 16;
        output[i] = letters[remainder];
        i++;
    }
    output[i] = '\0';
    my_putstr("0x");
    my_putstr(strrev(output));
}

void print_percentage(va_list arg)
{
    my_putchar('%');
}