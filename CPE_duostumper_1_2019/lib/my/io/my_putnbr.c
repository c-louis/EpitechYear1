/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** my_putnbr
*/

#include "../my.h"

int my_putnbr(int nb)
{
    int modulo = 1;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        modulo = nb % 10;
        my_putchar(modulo + 48);
    }
    return (nb);
}

int my_putnbr_unsigned(unsigned int nb)
{
    int modulo = 1;

    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_putnbr_unsigned(nb / 10);
        modulo = nb % 10;
        my_putchar(modulo + 48);
    }
    return (nb);
}