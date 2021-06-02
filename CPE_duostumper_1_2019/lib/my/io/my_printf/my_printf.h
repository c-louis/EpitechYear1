/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** my_printf's Include file
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

void print_c(va_list arg);

void print_d(va_list arg);

void print_s(va_list arg);

void print_p(va_list arg);

void print_o(va_list arg);

void print_x_lc(va_list arg);

void print_x(va_list arg);

void print_b(va_list arg);

void print_u(va_list arg);

void print_p(va_list arg);

void print_percentage(va_list arg);

char *convert_base_lc(int nb, int base);

int my_put_uint(unsigned int nb);

#endif /* !MY_PRINTF_H_ */