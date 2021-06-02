/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** is_different
*/

#include "../my.h"

int is_different(char const *str1, char const *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 1;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 1;
    return 0;
}