/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** path handling
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "my.h"
#include "shell.h"

int get_path_size(char *path_env, int i)
{
    int y = 0;
    for (; path_env[i] != ':' && path_env[i] != '\0'; i++) {
        y++;
    }
    return (y);
}

int get_path_count(char *path_env)
{
    int path_count = 0;

    if (path_env == NULL)
        return (0);
    for (int i = 0; path_env[i] != '\0'; i++)
        if (path_env[i] == ':')
            path_count++;
    if (path_env[0] != '\0')
        path_count++;
    return (path_count);
}

char **get_paths(char **env)
{
    char *path_env = get_env("PATH", env);
    int path_count = get_path_count(path_env);
    int size = 0;
    int j = 0;
    int k = 0;
    char **paths = malloc(sizeof(char *) * (path_count + 1));

    if (path_env == NULL || path_env[5] == '\0')
        return (NULL);
    for (int i = 5; i < my_strlen(path_env); i += size + 1) {
        j = 0;
        size = get_path_size(path_env, i);
        paths[k] = malloc(sizeof(char) * size + 1);
        for (int y = i; y < i+size; y++)
            paths[k][j++] = path_env[y];
        paths[k++][size] = '\0';
    }
    paths[path_count] = NULL;
    return (paths);
}

char *find_path(char **arg, char **env)
{
    char **paths = get_paths(env);
    char *path;

    if (paths == NULL)
        return (NULL);
    for (int i = 0; paths[i] != NULL; i++) {
        path = malloc(my_strlen(paths[i]) + 2 + my_strlen(arg[0]));
        path[0] = '\0';
        my_strcat(path, paths[i]);
        my_strcat(path, "/");
        my_strcat(path, arg[0]);
        if (access(path, F_OK) != -1) {
            free_array(paths);
            return (path);
        }
        free(path);
    }
    free_array(paths);
    return (NULL);
}
