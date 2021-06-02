/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** my_putstr
*/

#include "../my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}