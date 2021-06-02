/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** minishell1 env handling
*/

#include <stdlib.h>

#include "shell.h"
#include "my.h"

char **copy_env(char **env)
{
    char **shell_env = NULL;
    int i = 0;

    for (; env[i] != NULL; i++);
    shell_env = malloc(sizeof(char *) * (i+1));
    if (!shell_env)
        return (0);
    for (int y = 0; env[y] != NULL; y++) {
        shell_env[y] = my_strdup(env[y]);
        if (!shell_env[y])
            return (0);
    }
    shell_env[i] = NULL;
    return (shell_env);
}

char *get_env(char *arg, char **env)
{
    if (!arg)
        return (NULL);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(arg, env[i], my_strlen(arg)) == 0
            && env[i][my_strlen(arg)] == '=') {
            return (env[i]);
        }
    }
    return (NULL);
}

void remove_env_to_null(char *arg, char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    for (int y = 0; y < i; y++) {
        if (my_strlen(arg) == get_env_n_size(env[y]) &&
            my_strncmp(arg, env[y], get_env_n_size(env[y])) == 0) {
            free(env[y]);
            env[y] = NULL;
        }
    }
}

void remove_env(char *arg, char ***env_adress)
{
    int i = 0;
    int index = 0;
    char **env = *env_adress;
    char **new_env;

    while (env[i] != NULL)
        i++;
    if (i == 0)
        return;
    remove_env_to_null(arg, env);
    new_env = malloc(sizeof(char *) * i);
    if (!new_env)
        return;
    for (int y = 0; y < i; y++)
        if (env[y] != NULL)
            new_env[index++] = env[y];
    new_env[i- 1] = NULL;
    free(env);
    *env_adress = new_env;
}

void add_env(char *arg, char ***env_adress)
{
    char **env = *env_adress;
    char **new_env;
    int i = 0;

    while (env[i] != NULL)
        i++;
    new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env)
        return;
    for (int y = 0; y < i; y++)
        new_env[y] = env[y];
    new_env[i] = arg;
    new_env[i + 1] = NULL;
    free(env);
    *env_adress = new_env;
}
