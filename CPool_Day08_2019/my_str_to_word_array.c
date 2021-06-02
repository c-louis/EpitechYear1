/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** split a string into a word array
*/

#include <stdlib.h>

int my_strlen(char const *str);

int is_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
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

int new_start(int old_start, char const *str)
{
    for (int i = old_start; i < my_strlen(str); i++) {
        if (is_alphanumeric(str[i]))
            return (i);
    }
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int dest_index = 0;
    char **dest;
    int str_lengh = my_strlen(str);
    int start = 0;

    dest = malloc(sizeof(char) * str_lengh + 1);
    while (str[i] != '\0') {
        if (!is_alphanumeric(str[i]) && start < i || str[i + 1] == '\0') {
            char *tmp;
            tmp = malloc(sizeof(char) * (i - start) + 1);
            copy_word(tmp, start, i, str);
            dest[dest_index] = tmp;
            dest_index++;
            start = new_start(i, str);
        }
        i++;
    }
    dest[dest_index] = 0;
    return (dest);
}
