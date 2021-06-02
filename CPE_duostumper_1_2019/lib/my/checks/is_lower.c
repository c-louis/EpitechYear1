/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_lower
*/

int	is_lower(char const c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int is_lower_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (is_lower(str[i]))
            i++;
        else
            return 0;
    return 1;
}