/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** show a list of word
*/

#include <stdlib.h>

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

int my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i] != 0) {
        int arg_lengh = my_strlen(tab[i]);
        char *dest;
        dest = malloc(sizeof(char) * (arg_lengh + 3));
        my_strcat(dest, tab[i]);
        dest[arg_lengh] = '\n';
        dest[arg_lengh + 1] = '\0';
        my_putstr(dest);
        free(dest);
        i++;
    }
    return (0);
}
