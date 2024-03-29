/*
** EPITECH PROJECT, 2019
** my_int_to_char
** File description:
** convert an int to a string
*/

#include "my.h"
#include <stdlib.h>

char *get_starting_pointer(char *s)
{
    int len = my_strlen(s);
    char *res = s;

    for (int i = 0; i < len; i++){
        if (s[i] != '0'){
            res = my_strncpy(res, &s[i], len - i);
            res[len - i] = '\0';
            return (res);
        }
    }
    res = my_strncpy(res, &s[len - 1], 1);
    res[1] = '\0';
    return (res);
}

int get_nbrsize(unsigned int nbr)
{
    int i = 0;
    while (nbr >= 10) {
        nbr = nbr / 10;
        i++;
    }
    return (i);
}

char *my_int_char(unsigned int nbr)
{
    int is_neg = 0;
    int i = get_nbrsize(nbr);
    char *to_return = malloc(i + 3 + is_neg);
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
