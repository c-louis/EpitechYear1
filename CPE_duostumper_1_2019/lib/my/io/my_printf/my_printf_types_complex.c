/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_types2
*/

#include "../../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <limits.h>

void print_o(va_list arg)
{
    my_putstr(convert_base(va_arg(arg, int), 8));
}

void print_x_lc(va_list arg)
{
    my_putstr(convert_base_lc(va_arg(arg, int), 16));
}

void print_x(va_list arg)
{
    my_putstr(convert_base(va_arg(arg, int), 16));
}

void print_b(va_list arg)
{
    my_putstr(convert_base(va_arg(arg, int), 2));
}

void print_u(va_list arg)
{
    int nb = va_arg(arg, int);
    unsigned int result;

    if (nb < 0)
        result = UINT_MAX + nb;
    my_put_uint(nb);
}