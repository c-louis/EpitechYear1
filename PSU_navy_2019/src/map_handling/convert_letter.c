/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert letter_on_map
*/

#include "my.h"

char letter_converter(char c)
{
    char letter[] = "ABCDEFGH";

    for (int i = 0; letter[i]; i++) {
        if (letter[i] == c) {
            return ('1' + i);
        }
    }
    return (c);
}

int verify_data(char c)
{
    if (c == ':')
        return (0);
    else if (c < '1' || c > '8')
        return (0);
    return (1);
}

int convert_letter_on_map(char **data_map)
{
    int error = 0;

    for (int i = 0; data_map[i]; i++) {
        for (int j = 0; data_map[i][j]; j++) {
            data_map[i][j] = letter_converter(data_map[i][j]);
            error += verify_data(data_map[i][j]);
        }
    }
    if (!error) {
        my_printf("74\n");
        return (84);
    }
    return (0);
}
