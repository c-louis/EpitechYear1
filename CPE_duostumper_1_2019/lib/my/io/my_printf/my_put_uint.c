/*
** EPITECH PROJECT, 2020
** PSU_my_printf_2019
** File description:
** my_put_uint
*/

#include "../../my.h"

int my_put_uint(unsigned int nb)
{
    int modulo = 1;

    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_uint(nb / 10);
        modulo = nb % 10;
        my_putchar(modulo + 48);
    }
    return (nb);
}