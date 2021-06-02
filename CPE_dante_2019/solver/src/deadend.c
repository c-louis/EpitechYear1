/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main_solver
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "dante.h"

int count_deadend(char **maze_cpy, maze_t *maze_p)
{
    int d_c = 0;

    for (int i = 0; maze_cpy[i]; i++)
        for (int y = 0; maze_cpy[y]; y++)
            d_c = is_dend(i, y, maze_cpy, maze_p) ? d_c  + 1 : d_c;
    return (d_c);
}

deadend_t **get_deadend(char **maze_cpy, maze_t *maze_p)
{
    int d_c = count_deadend(maze_cpy, maze_p);
    deadend_t **deadend_l;

    deadend_l = malloc(sizeof(deadend_t *) * (d_c + 1));
    d_c = 0;
    for (int i = 0; maze_cpy[i]; i++)
        for (int y = 0; maze_cpy[i][y]; y++) {
            if (maze_cpy[i][y] != '*' || (i == 0 && y == 0))
                continue;
            if (is_dend(i, y, maze_cpy, maze_p)) {
                deadend_l[d_c] = malloc(sizeof(deadend_t));
                deadend_l[d_c]->x = y;
                deadend_l[d_c++]->y = i;
            }
        }
    deadend_l[d_c] = NULL;
    return (deadend_l);
}

int deadend_next(deadend_t *dd, char **maze_cpy, char c)
{
    if (dd->x != 0 && maze_cpy[dd->y][dd->x - 1] == c) {
        dd->x = dd->x - 1;
        return (1);
    }
    if (dd->y != 0 && maze_cpy[dd->y - 1][dd->x] == c) {
        dd->y = dd->y - 1;
        return (1);
    }
    if (maze_cpy[dd->y][dd->x+1] != 0 && maze_cpy[dd->y][dd->x+1] != '\n'
        && maze_cpy[dd->y][dd->x+1] == c) {
        dd->x = dd->x + 1;
        return (1);
    }
    if (maze_cpy[dd->y+1] != 0 && maze_cpy[dd->y+1][dd->x] == c) {
        dd->y = dd->y + 1;
        return (1);
    }
    return (0);
}

void fill_deadend(deadend_t *dd, char **maze_cpy)
{
    int w_c = 3;
    while (w_c > 2 && w_c != 4) {
        w_c = wall_count(dd->y, dd->x, maze_cpy);
        if (w_c <= 2)
            continue;
        maze_cpy[dd->y][dd->x] = 'X';
        deadend_next(dd, maze_cpy, '*');
    }
}

void fill_deadends(char **maze_cpy, maze_t *maze_p)
{
    deadend_t **deadends = get_deadend(maze_cpy, maze_p);

    for (int i = 0; deadends[i]; i++)
        fill_deadend(deadends[i], maze_cpy);
}
