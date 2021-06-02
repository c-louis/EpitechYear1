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

void check_maze(char **maze)
{
    for (int i = 0; maze[i]; i++) {
        for (int y = 0; maze[i][y]; y++) {
            check_char(maze[i][y], maze);
        }
    }
}

char **copy_maze(char **maze)
{
    char **maze_cpy;
    int size = 0;

    for (; maze[size]; size++);
    maze_cpy = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; maze[i]; i++)
        maze_cpy[i] = strdup(maze[i]);
    maze_cpy[size] = NULL;
    return (maze_cpy);
}

int wall_count(int y, int x, char **maze)
{
    int wall_c = 0;

    if (maze[y + 1] == NULL) wall_c++;
    else wall_c = (maze[y+1][x] == 'X' ? wall_c + 1 : wall_c);
    if (x != 0) wall_c = maze[y][x - 1] == 'X' ? wall_c + 1 : wall_c;
    else wall_c++;
    if (y != 0) wall_c = maze[y - 1][x] == 'X' ? wall_c + 1 : wall_c;
    else wall_c++;
    if (maze[0][x + 1] == '\n' || maze[0][x + 1] == '\0') wall_c++;
    else wall_c = maze[y][x + 1] == 'X' ? wall_c + 1 : wall_c;
    if (x == 0 && y == 0) wall_c = wall_c - 2;
    return (wall_c);
}

int is_dend(int y, int x, char **maze, maze_t *maze_p)
{
    int wall_c = 0;

    if (x == (maze_p->width - 2) && y == (maze_p->height - 1))
        return (0);
    wall_c = wall_count(y, x, maze);
    if (wall_c >= 3)
        return (1);
    return (0);
}

deadend_t *fill_result(char **maze, maze_t *maze_p)
{
    deadend_t *dd = malloc(sizeof(deadend_t));
    deadend_t *inter = malloc(sizeof(deadend_t));
    int w_c = 0;
    int inter_set = 0;

    dd->x = maze_p->width - 2;
    dd->y = maze_p->height - 1;
    while (!(dd->x == 0 && dd->y == 0)) {
        maze[dd->y][dd->x] = 'o';
        w_c = wall_count(dd->y, dd->x, maze);
        if (!deadend_next(dd, maze, '*')) {
            return (inter_set == 1 ? inter : NULL);
        } else if (w_c < 2) {
            inter->x = dd->x;
            inter->y = dd->y;
            inter_set = 1;
        }
    }
    maze[0][0] = 'o';
    return NULL;
}