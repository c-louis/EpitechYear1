/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_alphanum
*/

#include "../my.h"

int	is_alphanum(char const c)
{
    if (is_lower(c) || is_upper(c) || is_numeric(c))
        return 1;
    return 0;
}

int is_alphanum_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (is_alphanum(str[i]))
            i++;
        else
            return 0;
    return 1;
}