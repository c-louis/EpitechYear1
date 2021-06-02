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

void check_end(char **maze)
{
    if (maze[0][0] == 'o')
        return;
    printf("no solution found");
    exit(0);
}

void solve_maze(char **maze_str, maze_t *maze_p)
{
    char **maze_cpy = copy_maze(maze_str);
    char **tmp_maze;
    deadend_t *inter;

    fill_deadends(maze_cpy, maze_p);
    tmp_maze = copy_maze(maze_cpy);
    inter = fill_result(tmp_maze, maze_p);
    while (inter != NULL) {
        free_array(tmp_maze);
        maze_cpy[inter->y][inter->x] = 'X';
        tmp_maze = copy_maze(maze_cpy);
        inter = fill_result(tmp_maze, maze_p);
    }
    check_end(tmp_maze);
    for (int i = 0; tmp_maze[i]; i++)
        for (int y = 0; tmp_maze[i][y]; y++)
            if (tmp_maze[i][y] == 'o')
                maze_str[i][y] = 'o';
    free_array(tmp_maze);
}

int main(int ac, char **av)
{
    char **maze_str;
    maze_t maze_p = (maze_t) {0, 0};

    if (ac != 2)
        return (84);
    maze_str = get_maze(av[1]);
    check_maze(maze_str);
    for (; maze_str[maze_p.height]; maze_p.height = maze_p.height + 1);
    for (; maze_str[0][maze_p.width]; maze_p.width = maze_p.width + 1);
    solve_maze(maze_str, &maze_p);
    for (int i = 0; maze_str[i]; i++)
        printf("%s", maze_str[i]);
    return (0);
}
