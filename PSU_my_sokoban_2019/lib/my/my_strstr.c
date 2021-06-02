/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** reproduce _strstr from string lib
*/

#include <stddef.h>

int my_strlen(char const *str);

int check_next_caracter(char *str, char const *to_find, int start)
{
    int i = 1;
    while (i < my_strlen(to_find)) {
        if (str[start + i] != to_find[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    if (to_find[0] == '\0')
        return (str);
    while (str[i] != '\0') {
        if (str[i] == to_find[0] && check_next_caracter(str, to_find, i)) {
            return (&str[i]);
        }
        i++;
    }
    return (NULL);
}
