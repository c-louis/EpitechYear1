/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include "../../my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int is_type(char type)
{
    char valid_types[] = {
        'c', 'd', 'i', 's',
        'o', 'x', 'X', 'b',
        'u', 'p', '%'
    };

    for (int i = 0; i < 10; i++)
        if (valid_types[i] == type)
            return 1;
    return 0;
}

int count_args(const char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '%' && str[i - 1] != '\\' && is_type(str[i + 1]))
            counter++;
    return counter;
}

void write_arg(va_list args, char type)
{
    int i = 0;
    void (*types[])(va_list) = {
        print_c, print_d, print_d, print_s,
        print_o, print_x_lc, print_x, print_b,
        print_u, print_p, print_percentage
    };
    char letters[] = {
        'c', 'd', 'i', 's',
        'o', 'x', 'X', 'b',
        'u', 'p', '%'
    };

    for (; letters[i] != type; i++);
    (*types[i])(args);
}

int my_printf(char const *str, ...)
{
    va_list args;

    va_start(args, count_args(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '%') {
            write_arg(args, str[i + 1]);
            i++;
        } else if (str[i] == '%' && str[i - 1] != '\\' && is_type(str[i + 1])) {
            write_arg(args, str[i + 1]);
            i++;
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}

char *convert_base_lc(int nb, int base)
{
    int i = 1;
    int remainder;
    int tmp;
    char *letters = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *output = malloc(sizeof(char) * 100);

    output[i--] = '\n';
    while (nb != 0) {
        tmp = nb;
        nb /= base;
        remainder = tmp % base;
        if (remainder > 36)
            return "LETTER OVERFLOW";
        output[i] = letters[remainder];
        i++;
    }
    return (strrev(output));
}