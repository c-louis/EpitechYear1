/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell setenv function
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

int setenv_check(char *str)
{
    if (!((str[0] >= 'A' && str[0] <= 'Z') ||
        (str[0] >= 'a' && str[0] <= 'z'))) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == '.'))) {
            write(2,
            "setenv: Variable name must contain alphanumeric characters.\n",
            60);
            return (1);
        }
    }
    return (0);
}

int check_var(char **cmd)
{
    if (cmd[1] != NULL && cmd[2] != NULL && cmd[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (1);
    }
    return (0);
}

int buildin_setenv(char **cmd, char ***env)
{
    int len = (((cmd[1] != NULL) ? my_strlen(cmd[1]) +
              ((cmd[2] != NULL) ? my_strlen(cmd[2]) : 0) : 0) + 2);
    char *arg = malloc(len + 1);
    arg[0] = '\0';
    if (cmd[1] == NULL) {
        buildin_env(cmd, env);
        return (0);
    }
    if (setenv_check(cmd[1]) == 1 || check_var(cmd) == 1)
        return (1);
    if (get_env(cmd[1], *env) != NULL)
        remove_env(cmd[1], env);
    my_strcat(arg, cmd[1]);
    my_strcat(arg, "=");
    if (cmd[2] != NULL)
        my_strcat(arg, cmd[2]);
    arg[len] = '\0';
    add_env(arg, env);
    return (0);
}
