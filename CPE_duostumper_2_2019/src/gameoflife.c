/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include <stdlib.h>

#include "project.h"

void loop(int **table, t_params param, int **new_table)
{
    int count = count_nearby(table, param);

    if (count <= 1 || count >= 4)
        new_table[param.y][param.x] = 0;
    if (count == 3 || (count == 2 && table[param.y][param.x] == 1))
        new_table[param.y][param.x] = 1;
    else
        new_table[param.y][param.x] = 0;
}

int **gameoflife(int **table, t_params params)
{
    int **new_table = malloc(sizeof(int *) * (params.height));

    for (int i = 0; i < params.height; i++)
        new_table[i] = malloc(sizeof(int) * (params.width));
    for (int y = 0; y < params.height; y++) {
        for (int x = 0; x < params.width; x++) {
            params.x = x;
            params.y = y;
            loop(table, params, new_table);
        }
    }
    for (int i = 0; i < params.height; i++)
        free(table[i]);
    free(table);
    return (new_table);
}
