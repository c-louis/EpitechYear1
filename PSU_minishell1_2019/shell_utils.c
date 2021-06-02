/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** shell utility function (free and others)
*/

#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

int get_env_n_size(char *var)
{
    int i = 0;

    for (; var[i] != '=' && var[i] != '\0'; i++);
    return (i);
}

void *free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    array = NULL;
}

void set_oldpwd(char **cmd, char ***env, char *pwd)
{
    char *oldpwd;

    if (get_env("OLDPWD", *env) != NULL)
        remove_env("OLDPWD", env);
    oldpwd = malloc(my_strlen(pwd) + 8);
    oldpwd[0] = '\0';
    my_strcat(oldpwd, "OLDPWD=");
    my_strcat(oldpwd, pwd);
    free(pwd);
    add_env(oldpwd, env);
}
