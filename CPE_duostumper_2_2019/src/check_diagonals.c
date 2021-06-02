/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include "project.h"

void check_top_left(int *count, int **table, t_params params)
{
    if (params.x > 0 && params.y > 0)
        if (table[params.y - 1][params.x - 1])
            (*count)++;
}

void check_top_right(int *count, int **table, t_params params)
{
    if (params.x < (params.width  - 1) && params.y > 0)
        if (table[params.y - 1][params.x + 1])
            (*count)++;
}

void check_bottom_left(int *count, int **table, t_params params)
{
    if (params.y < (params.height - 1) && params.x > 0)
        if (table[params.y + 1][params.x - 1])
            (*count)++;
}

void check_bottom_right(int *count, int **table, t_params params)
{
    if (params.y < (params.height - 1) && params.x < (params.width - 1))
        if (table[params.y + 1][params.x + 1])
            (*count)++;
}
