/*
** EPITECH PROJECT, 2019
** my_strdrup
** File description:
** copy str and return it in a new one
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int src_lengh = my_strlen(src);
    char *dest;
    dest = malloc(sizeof(char) * src_lengh +1);
    int i = 0;
    while (i < src_lengh) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
