/*
** EPITECH PROJECT, 2019
** print utils
** File description:
** rint utils 2
*/

#include <stdarg.h>
#include "my.h"

int pr_uint(va_list ap)
{
    unsigned int num = va_arg(ap, unsigned int);
    my_put_uint(num);
    return (determine_uint_size(num));
}

int pr_hexa(va_list ap)
{
    int num = va_arg(ap, int);
    int lenght = my_putnbr_base(num, "0123456789ABCDEF");
    return (lenght);
}

int pr_oct(va_list ap)
{
    int num = va_arg(ap, int);
    int lenght = my_putnbr_base(num, "01234567");
    return (lenght);
}

int pr_percent(va_list ap)
{
    my_putchar('%');
    return (1);
}

int pr_pointer(va_list ap)
{
    return (0);
}
