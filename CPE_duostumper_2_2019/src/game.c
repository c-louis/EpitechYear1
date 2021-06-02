/*
** EPITECH PROJECT, 2020
** game_of_life
** File description:
** game things
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "project.h"

t_params get_params(char **map)
{
    t_params params;
    int size = 0;

    for (; map[size]; size++);
    params.width = strlen(map[0]) - 1;
    params.height = size;
    return (params);
}

int **translate_map(char **file, t_params params)
{
    int **map = malloc(sizeof(int *) * (params.height + 1));

    for (int i = 0; i < params.height; i++)
        map[i] = malloc(sizeof(int) * params.width);
    for (int i = 0; file[i]; i++) {
        for (int y = 0; file[i][y + 1]; y++) {
            map[i][y] = file[i][y] == '.' ? 0 : 1;
        }
    }
    for (int i = 0; file[i]; i++)
        free(file[i]);
    free(file);
    return (map);
}

int start_game(char **file, int generation)
{
    t_params params = get_params(file);
    int **map = translate_map(file, params);

    for (int i = 0; i < generation; i++)
        map = gameoflife(map, params);
    for (int i = 0; i < params.height; i++) {
        for (int y = 0; y < params.width; y++) {
            printf("%c", map[i][y] == 0 ? '.' : 'X');
        }
        printf("\n");
    }
    for (int i = 0; i < params.height; i++)
        free(map[i]);
    free(map);
    return (0);
}
