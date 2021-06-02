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

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void maze_exit(char **maze, int exit_code, char *error_message)
{
    for (int i = 0; maze[i]; i++)
        free(maze[i]);
    free(maze);
    dprintf(2, error_message);
    exit(exit_code);
}

void push_string(char ***ad_maze, char *new_line)
{
    int size = 0;
    char **new_maze = NULL;
    char **maze = *ad_maze;

    for (; maze[size]; size++);
    new_maze = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; maze[i]; i++)
        new_maze[i] = maze[i];
    new_maze[size] = strdup(new_line);
    new_maze[size + 1] = NULL;
    free(maze);
    *ad_maze = new_maze;
}

char **get_maze(char *path)
{
    FILE *stream;
    char *line = NULL;
    size_t len;
    ssize_t read;
    char **maze = malloc(sizeof(char *));

    maze[0] = NULL;
    stream = fopen(path, "r");
    if (stream == NULL) {
        perror("Maze Error");
        exit(84);
    }
    while ((read = getline(&line, &len, stream)) != -1)
        push_string(&maze, line);
    free(line);
    fclose(stream);
    return (maze);
}

void check_char(char c, char **maze)
{
    if (c != 'X' && c != '*' && c != '\n') {
        maze_exit(maze, 84, "The maze contain invalid character");
    }
}
