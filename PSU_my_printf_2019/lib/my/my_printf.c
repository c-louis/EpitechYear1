/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf functions
*/

#include <stdarg.h>
#include "my.h"

int disp_stdarg(char s, va_list ap)
{
    int (*pr[])(va_list) = {pr_str, pr_int, pr_int, pr_char,
                            pr_bin, pr_allstr, pr_uint, pr_hexa,
                            pr_hexa, pr_oct, pr_percent, pr_pointer};
    char *corres[] = {"s", "d", "i", "c", "b", "S",
                      "u", "x", "X", "o", "%", "p"};
    int i = 0;
    for (i = 0; s != corres[i][0]; i++);
    int printed = (*pr[i])(ap);
    return(printed);
}

int my_printf(char *str, ...)
{
    va_list ap;
    int printed = 0;
    va_start(ap, str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '%') {
            my_putchar(str[i]);
            printed++;
        } else {
            int quant = disp_stdarg(str[i+1], ap);
            printed += quant;
            i += 1;
        }
    }
    va_end(ap);
    return (printed);
}
