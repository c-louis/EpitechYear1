/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include "project.h"

void check_left(int *count, int **table, t_params params)
{
    if (params.x > 0)
        if (table[params.y][params.x - 1])
            (*count)++;
}

void check_right(int *count, int **table, t_params params)
{
    if (params.x < (params.width - 1))
        if (table[params.y][params.x + 1])
            (*count)++;
}

void check_top(int *count, int **table, t_params params)
{
    if (params.y > 0)
        if (table[params.y - 1][params.x])
            (*count)++;
}

void check_bottom(int *count, int **table, t_params params)
{
    if (params.y < (params.height - 1))
        if (table[params.y + 1][params.x])
            (*count)++;
}

int count_nearby(int **table, t_params params)
{
    int count = 0;

    check_left(&count, table, params);
    check_right(&count, table, params);
    check_top(&count, table, params);
    check_bottom(&count, table, params);
    check_top_left(&count, table, params);
    check_top_right(&count, table, params);
    check_bottom_left(&count, table, params);
    check_bottom_right(&count, table, params);
    return count;
}
