/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_numeric
*/

int	is_numeric(char const c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int is_numeric_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (is_numeric(str[i]))
            i++;
        else
            return 0;
    return 1;
}