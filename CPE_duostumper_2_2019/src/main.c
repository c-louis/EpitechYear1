/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "project.h"

int is_file_valid(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        perror("File error");
        return (0);
    }
    return (1);
}

void push_string(char ***array, char *string)
{
    int size = 0;
    char **new_array = NULL;
    char **old_array = *array;

    for (; old_array[size]; size++);
    new_array = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; old_array[i]; i++)
        new_array[i] = old_array[i];
    new_array[size] = strdup(string);
    new_array[size + 1] = NULL;
    free(old_array);
    *array = new_array;
}

char **get_file(char *path)
{
    FILE *stream;
    char *line = NULL;
    size_t len;
    ssize_t read;
    char **map = malloc(sizeof(char *));

    map[0] = NULL;
    stream = fopen(path, "r");
    if (stream == NULL) {
        perror("File error");
        exit(84);
    }
    while ((read = getline(&line, &len, stream)) != -1) {
        push_string(&map, line);
    }
    free(line);
    fclose(stream);
    return (map);
}

int game_of_life(int ac, char **av)
{
    char *path = av[1];
    int generation = atoi(av[2]);
    char **map = NULL;

    if (!is_file_valid(path)) {
        return (84);
    }
    map = get_file(path);
    if (!is_map_okay(map)) {
        return (84);
    }
    return (start_game(map, generation));
}

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    return (game_of_life(ac, av));
}
