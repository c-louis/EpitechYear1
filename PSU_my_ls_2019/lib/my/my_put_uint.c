/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the given number
*/

#include "my.h"

int determine_uint_size(unsigned int nb)
{
    int i = 0;

    for (i; nb >= 10 || nb <= -10; i++) {
        nb /= 10;
    }
    return (i);
}

void display_all_uint(int nb_size, unsigned int nb)
{
    unsigned int tmp_nb;

    while (nb_size >= 0) {
        tmp_nb = nb / (ten_power(nb_size));
        if (tmp_nb < 0)
            tmp_nb = tmp_nb * -1;
        if (tmp_nb >= 10) {
            tmp_nb = tmp_nb % 10;
        }
        tmp_nb = tmp_nb + 48;
        my_putchar(tmp_nb);
        nb_size--;
        if (nb == -2147483648 && nb_size == 0)
            nb_size--;
    }
}

int my_put_uint(unsigned int nb)
{
    int nb_size;

    nb_size = determine_uint_size(nb);
    display_all_uint(nb_size, nb);
    return (0);
}
