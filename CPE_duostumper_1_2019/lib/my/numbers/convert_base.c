/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** convert_base
*/

#include "../my.h"
#include <stdlib.h>

char *convert_base(int nb, int base)
{
    int i = 1;
    int remainder;
    int tmp;
    char *letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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