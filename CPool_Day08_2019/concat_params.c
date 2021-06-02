/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** concat parameter
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src);

char *concat_params(int argc, char **argv)
{
    int argv_len = 0;
    char *dest;

    for (int i = 0; i < argc; i++) {
        argv_len = argv_len + my_strlen(argv[i]);
        argv_len++;
    }
    dest = malloc(sizeof(char) * argv_len);
    for (int i = 0; i < argc; i++) {
        my_strcat(dest, argv[i]);
        if (i != argc - 1)
            my_strcat(dest, "\n");
    }
    dest[argv_len + 1] = '\0';
    return (dest);
}
