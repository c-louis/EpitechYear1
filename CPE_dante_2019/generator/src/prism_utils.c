/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** prism_utils
*/

#include <stdlib.h>
#include <stddef.h>
#include "dante.h"
#include "my.h"

int is_correct_wall(list_t *wall, char **maze, int x, int y)
{
    if (x < 0 || y < 0)
        return (0);
    else if (x >= wall->width_maze || y >= wall->height_maze)
        return (0);
    if (maze[y][x] != 'X')
        return (0);
    return (1);
}

int set_wall_from_cell(list_t *wall, char **maze, int x, int y)
{
    int error = 0;

    error += is_correct_wall(wall, maze, x - 1, y) ?
        add_wall_to_list(wall, x - 1, y) : 0;
    error += is_correct_wall(wall, maze, x + 1, y) ?
        add_wall_to_list(wall, x + 1, y) : 0;
    error += is_correct_wall(wall, maze, x, y - 1) ?
        add_wall_to_list(wall, x, y - 1) : 0;
    error += is_correct_wall(wall, maze, x, y + 1) ?
        add_wall_to_list(wall, x, y + 1) : 0;
    maze[y][x] = '*';
    if (error != 0)
        return (84);
    return (0);
}