/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** prism_generator
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "dante.h"
#include "my.h"

int is_cell_visited(list_t *wall, char **maze, int x, int y)
{
    int x_visited = 0;
    int y_visited = 0;

    if (x != wall->width_maze - 1)
        x_visited += (maze[y][x + 1] == 'n') ? 1 : 0;
    if (y != wall->height_maze - 1)
        y_visited += (maze[y + 1][x] == 'n') ? 1 : 0;
    if (y != 0 && y_visited == 0)
        y_visited += (maze[y - 1][x] == 'n') ? 1 : 0;
    if (x != 0 && x_visited == 0)
        x_visited += (maze[y][x - 1] == 'n') ? 1 : 0;
    if (x_visited == 1 || y_visited == 1)
        return (1);
    return (0);
}

int get_x_cell(char **maze, list_t *wall, chain_t *pickup_wall, int *x)
{
    if (pickup_wall->x_cell != 0) {
        if (maze[pickup_wall->y_cell][pickup_wall->x_cell - 1] == 'n') {
            *x = pickup_wall->x_cell - 1;
            return (1);
        }
    }
    if (pickup_wall->x_cell != wall->width_maze - 1) {
        if (maze[pickup_wall->y_cell][pickup_wall->x_cell + 1] == 'n') {
            *x = pickup_wall->x_cell + 1;
            return (1);
        }
    }
    *x = pickup_wall->x_cell;
    return (0);
}

int get_y_cell(char **maze, list_t *wall, chain_t *pickup_wall, int *y)
{
    if (pickup_wall->y_cell != 0) {
        if (maze[pickup_wall->y_cell - 1][pickup_wall->x_cell] == 'n') {
            *y = pickup_wall->y_cell - 1;
            return (1);
        }
    }
    if (pickup_wall->y_cell != wall->height_maze - 1) {
        if (maze[pickup_wall->y_cell + 1][pickup_wall->x_cell] == 'n') {
            *y = pickup_wall->y_cell + 1;
            return (1);
        }
    }
    *y = pickup_wall->y_cell;
    return (0);
}

int prism_loop(list_t *wall, char **maze)
{
    chain_t *pickup_wall = NULL;
    int x_cell = 0;
    int y_cell = 0;

    set_wall_from_cell(wall, maze, x_cell, y_cell);
    while (wall->length != 0) {
        pickup_wall = get_random_wall(wall);
        if (is_cell_visited(wall, maze, pickup_wall->x_cell,
            pickup_wall->y_cell)) {
            get_x_cell(maze, wall, pickup_wall, &x_cell);
            get_y_cell(maze, wall, pickup_wall, &y_cell);
            maze[pickup_wall->y_cell][pickup_wall->x_cell] = '*';
            set_wall_from_cell(wall, maze, x_cell, y_cell);
        }
        remove_wall(wall, pickup_wall->id, pickup_wall);
    }
    return (0);
}

int prism_generator(char **maze, int perfect, int width, int height)
{
    list_t wall;

    wall.length = 0;
    wall.width_maze = width;
    wall.height_maze = height;
    wall.head = NULL;
    prism_loop(&wall, maze);
    if (perfect == 0)
        make_imperfect(maze, width, height);
    return (0);
}