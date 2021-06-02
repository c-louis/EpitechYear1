/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_printable
*/

int	is_printable(char const c)
{
    if (c >= 32 && c != 127)
        return 1;
    return 0;
}

int is_printable_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (is_printable(str[i]))
            i++;
        else
            return 0;
    return 1;
}