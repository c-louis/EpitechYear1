/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** ucfirst
*/

char *ucfirst(char *str)
{
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    return str;
}