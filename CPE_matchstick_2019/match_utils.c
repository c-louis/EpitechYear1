/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick_utils
*/

#include <stdlib.h>

#include "my.h"

int check_win(int *map, int mapsize)
{
    for (int i = 0; i < mapsize; i++) {
        if (map[i] > 0)
            return (0);
    }
    return (1);
}

void print_win(int win)
{
    if (win == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    if (win == 2)
        my_printf("You lost, too bad...\n");
}

int *make_map(int mapsize)
{
    int *map = malloc(sizeof(int) * mapsize);

    for (int i = 0; i < mapsize; i++) {
        map[i] = 1 + 2*i;
    }
    return (map);
}
