/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Duplicates the input str
*/

#include <stdlib.h>

int my_strlen(char const *src);

char *my_strdup(char const *str)
{
    int len = my_strlen(str) + 1;
    char *copy = malloc(sizeof(char) * len);
    int i = 0;

    for (; str[i] != '\0'; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return (copy);
}
