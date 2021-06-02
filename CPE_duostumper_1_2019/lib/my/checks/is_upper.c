/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_upper
*/

int	is_upper(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int is_upper_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (is_upper(str[i]))
            i++;
        else
            return 0;
    return 1;
}