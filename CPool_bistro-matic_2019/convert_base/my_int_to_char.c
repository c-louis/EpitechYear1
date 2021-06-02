/*
** EPITECH PROJECT, 2019
** my_int_to_char
** File description:
** convert an int to a string
*/

#include "my.h"
#include "inf_utils.h"
#include <stdlib.h>

int get_nbrsize(int nbr)
{
    int i = 0;
    while (nbr >= 10) {
        nbr = nbr / 10;
        i++;
    }
    return (i);
}

char *my_int_char(int nbr)
{
    int is_neg = 0;
    if (nbr < 0) {
        is_neg++;
        nbr *= -1;
    }
    int i = get_nbrsize(nbr);
    char *to_return = malloc(i + 2 + is_neg);
    int y = 1;
    to_return[0] = '0';
    for (; i >= 0; i--) {
        char tmp = (nbr / my_compute_power_rec(10, i) % 10) + '0';
        to_return[y++] = tmp;
    }
    to_return[y] = '\0';
    if (is_neg) {
        to_return[0] = '-';
        return (get_starting_pointer(to_return));
    }
    return (get_starting_pointer(to_return));
}
