/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include "my.h"
#include "project.h"

void err_invalidarg(char *str, struct options *opt)
{
    my_putstr("tail: invalid number of ");
    if (str[1] == 'c')
        my_putstr("bytes");
    else if (str[1] == 'n')
        my_putstr("lines");
    my_printf(": \'%s\'");
    (*opt).ret = 1;
}

