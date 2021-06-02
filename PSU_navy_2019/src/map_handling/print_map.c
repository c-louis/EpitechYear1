/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** print_map
*/

#include "my.h"

void print_map(int **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        my_printf("%c", map[i][0]);
        for (int j = 1; j < 8; j++) {
            my_printf(" %c", map[i][j]);
        }
        my_printf("\n");
    }
}
