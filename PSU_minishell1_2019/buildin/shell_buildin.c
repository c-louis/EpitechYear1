/*
** EPITECH PROJECT, 2020
** shell_buildin
** File description:
** buildin function
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

int buildin_env(char **cmd, char ***env_ad)
{
    char **env = *env_ad;

    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return (0);
}

int buildin_exit(void)
{
    if (isatty(0))
        my_printf("exit\n");
    return (0);
}

int exec_buildin(char **cmd, char ***env, int *end)
{
    if (my_strcmp(cmd[0], "exit") == 0) {
        buildin_exit();
        *end = 1;
        return (1);
    }
    if (my_strcmp(cmd[0], "setenv") == 0) {
        buildin_setenv(cmd, env);
        return (1);
    }
    if (my_strcmp(cmd[0], "unsetenv") == 0) {
        buildin_unsetenv(cmd, env);
        return (1);
    }
    if (my_strcmp(cmd[0], "env") == 0)
        return (buildin_env(cmd, env));
    if (my_strcmp(cmd[0], "cd") == 0)
        return (buildin_cd(cmd, env));
    return (-1);
}
