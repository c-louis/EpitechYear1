/*
** EPITECH PROJECT, 2020
** tail
** File description:
** tail HEADER
*/

#include <stdlib.h>

#include "my.h"
#include "project.h"

int get_paths_size(char **paths)
{
    int size = 0;

    if (paths != NULL) {
        for (; paths[size]; size++);
        return (size);
    }
    return (0);
}

void add_path(char ***paths_list, char *new)
{
    int size = get_paths_size(*(paths_list));
    char **new_paths;
    char **paths = *paths_list;

    if (is_numeric_str(new))
        return;
    if (paths == NULL) {
        paths = malloc(2);
        paths[0] = new;
        paths[1] = NULL;
    }
    new_paths = malloc(sizeof(char *) * (size + 2));
    if (new_paths == NULL)
        return;
    for (int i = 0; paths[i]; i++)
        new_paths[i] = paths[i];
    new_paths[size] = new;
    new_paths[size + 1] = 0;
    *paths_list = new_paths;
}
