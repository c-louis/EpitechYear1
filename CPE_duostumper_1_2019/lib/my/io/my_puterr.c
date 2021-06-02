/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_puterr
*/

#include "../my.h"
#include <unistd.h>

void my_puterr(char const *error)
{
    write(2, error, my_strlen(error));
}