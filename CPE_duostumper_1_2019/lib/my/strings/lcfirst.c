/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** lcfirst
*/

char *lcfirst(char *str)
{
    if (str[0] >= 65 && str[0] <= 90)
        str[0] += 32;
    return str;
}