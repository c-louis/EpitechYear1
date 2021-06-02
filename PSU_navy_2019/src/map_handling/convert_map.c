/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert_map
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "navy.h"

int **load_blank_map(void)
{
    int size_map = 8;
    int **map = malloc(sizeof(int *) * size_map);

    if (!map) {
        my_printf("78\n");
        return (NULL);
    }
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * size_map);
        if (!map[i]) {
            my_printf("77\n");
            return (NULL);
        }
        for (int j = 0; j < size_map; j++)
            map[i][j] = '.';
    }
    return (map);
}

int **convert_map(char **data_map)
{
    int **map_final = load_blank_map();

    if (!map_final || verify_map(data_map) == 84) {
        my_printf("76\n");
        return (NULL);
    }
    else if (convert_letter_on_map(data_map) == 84 ||
            put_boat_on_map(data_map, map_final) == 84) {
        my_printf("75\n");
        return (NULL);
    }
    return (map_final);
}
