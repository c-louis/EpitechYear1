/*
** EPITECH PROJECT, 2020
** rrostring
** File description:
** rrostring
*/

#include <stdlib.h>
#include <stddef.h>

#include "my.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac != 2 || ac == 2 && av[1][0] == '\0') {
        my_printf("\n");
        return (0);
    }
    char **word = my_str_to_word_array(av[1]);
    if (word == NULL)
        return (84);
    for (; word[i] != NULL; i++);
    my_printf("%s ", word[i-1]);
    for (int y = 0; y < i-1; y++) {
        my_printf("%s", word[y]);
        if (y+1 < i-1)
            my_printf(" ");
    }
    my_printf("\n");
    free_array(word);
}
