/*
** EPITECH PROJECT, 2019
** print_function
** File description:
** printf_function to print different type
*/

#include "my.h"
#include <stdarg.h>

int pr_str(va_list ap)
{
    char *str = va_arg(ap, char *);
    my_putstr(str);
    return (my_strlen(str));
}

int pr_int(va_list ap)
{
    int num = va_arg(ap, int);
    my_put_nbr(num);
    return (determine_nb_size(num)+1);
}

int pr_char(va_list ap)
{
    char c = va_arg(ap, int);
    my_putchar(c);
    return (1);
}

int pr_bin(va_list ap)
{
    unsigned int num = va_arg(ap, unsigned int);
    int lenght = my_putnbr_base(num, "01");
    return (lenght);
}

int pr_allstr(va_list ap)
{
    char *str = va_arg(ap, char *);
    int lenght = 0;
    
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            if (str[i] < 40)
                my_putstr("0");
            if (str[i] < 8)
                my_putstr("0");
            my_putnbr_base(str[i], "01234567");
            lenght = lenght + 4;
        } else {
            my_putchar(str[i]);
            lenght++;
        }
    }
    return (lenght);
}

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
