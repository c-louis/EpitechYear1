/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick error handling
*/

#include "my.h"

int is_match_valid(int match, int take, int map_line)
{
    if (match > take) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
            take);
        return (0);
    }
    if (match <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (0);
    }
    if (map_line - match < 0) {
        my_printf("Error: not enough matches on this line\n");
        return (0);
    }
    return (1);
}

int is_line_valid(int line, int mapsize)
{
    if (line > mapsize || line < 0) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int is_match_number(char *input)
{
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    return (0);
}
