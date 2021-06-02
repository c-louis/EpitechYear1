/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** start_gen
*/

#include <stdlib.h>
#include <stdio.h>
#include "dante.h"
#include "my.h"

char **create_blank_map(int width, int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));

    if (!map)
        return (0);
    map[height] = NULL;
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * ( width+ 1));
        if (!map[i])
            return (0);
        map[i][width] = '\0';
        for (int j = 0; j < width; j++) {
            map[i][j] = 'n';
        }
    }
    return (map);
}

int pre_generation(char **map, int width, int height)
{
    for (int i = 1; i < height; i += 2) {
        for (int j = 0; j < width; j++) {
            map[i][j] = 'X';
        }
    }
    for (int i = 0; i < height; i += 2) {
        for (int j = 1; j < width; j += 2) {
            map[i][j] = 'X';
        }
    }
    map[height - 1][width - 1] = '*';
    if (height != 1) {
        if (width != 1)
            map[height - 1][width - 2] = '*';
        if (width != 1 && height > 2 && height % 2 == 1)
            map[height - 2][width - 2] = '*';
    }
    return (0);
}

int print_map(char **map)
{
    int i = 0;

    if (map == NULL)
        return (1);
    for (; map[i + 1]; i++) {
        printf("%s\n", map[i]);
    }
    printf("%s", map[i]);
    return (0);
}

int start_generator(int ac, char **av)
{
    int width = my_getnbr(av[1]);
    int height = my_getnbr(av[2]);
    int perfect = is_perfect(ac, av);
    char **map = create_blank_map(width, height);

    srand(&av);
    if (!map)
        return (-1);
    else if (width == 0 && height == 0)
        return (-1);
    pre_generation(map, width, height);
    prism_generator(map, perfect, width, height);
    print_map(map);
    free_my_str_array(map);
    return (0);
}