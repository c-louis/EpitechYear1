/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert_base
*/

#include <stdlib.h>

#include "my.h"

char *my_revstr(char *str)
{
    int len = 0;
    int loop = 0;
    char tmp = 0;

    len = my_strlen(str) - 1;
    while (len > loop) {
        tmp = str[len];
        str[len] = str[loop];
        str[loop] = tmp;
        len--;
        loop++;
    }
    return (str);
}

char *to_bin(int nb)
{
    int binary[10];
    int i = 0;

    for (; nb > 0; i++) {
        binary[i] = nb % 2;
        nb = nb / 2;
    }
    binary[i+1] = -1;
    char *bin = malloc(i+1);
    if (bin == NULL)
        return (NULL);
    for (int y = 0; y < i; y++)
        bin[y] = binary[y] + 48;
    bin[i] = '\0';
    return (my_revstr(bin));
}

int to_dec(int nb)
{
    int reste = 0;
    int result = 0;
    int base = 1;

    while (nb > 0) {
        reste = nb % 10;
        result = result + reste * base;
        nb /= 10;
        base *= 2;
    }
    return (result);
}
