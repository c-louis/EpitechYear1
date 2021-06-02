/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** split a string into a word array
*/

#include <stdlib.h>
#include "my.h"

int is_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 33 && c <= 46)
        return (1);
    if (c == ':')
        return (1);
    else
        return (0);
}

int compt_word(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\\') {
            i++;
            continue;
        }
        if (is_alphanumeric(str[i]) && !(is_alphanumeric(str[i + 1])))
            count++;
    }
    return (count);
}

void copy_word(char *tmp, int start, int end, char const *str)
{
    int y = 0;
    if (start > end) {
        return;
    }
    if (my_strlen(str) == end + 1) {
        end++;
    }
    for (int i = start; i < end; i++) {
        tmp[y] = str[i];
        y++;
    }
}

int get_lenght(char *str, int i)
{
    while (str[i] != '\0') {
        if (!is_alphanumeric(str[i]))
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_array(char *str)
{
    char **dest = malloc(sizeof(char *) * (compt_word(str) + 1));
    int start = 0;
    int c = 0;
    if (dest == NULL)
        return (NULL);
    for (int y = 0; y < compt_word(str); y++) {
        c = 0;
        while (!is_alphanumeric(str[start])) {
            if (str[start] == '\\')
                start++;
            start++;
        }
        dest[y] = malloc(sizeof(char) * (get_lenght(str, start) + 1));
        while (str[start] != '\0' && is_alphanumeric(str[start]))
            dest[y][c++] = str[start++];
        dest[y][c] = '\0';
    }
    dest[compt_word(str)] = 0;
    return (dest);
}
