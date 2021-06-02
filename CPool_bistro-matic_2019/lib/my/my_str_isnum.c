/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** check if input contains only numerical chars
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}
