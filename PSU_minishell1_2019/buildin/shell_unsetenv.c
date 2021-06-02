/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell_unsetenv function
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

int buildin_unsetenv(char **cmd, char ***env)
{
    if (cmd[1] == NULL)
        return (0);
    for (int i = 0; i < my_strlen(cmd[1]); i++)
        if (cmd[1][i] == '=')
            return (0);
    if (get_env(cmd[1], *env) != NULL)
        remove_env(cmd[1], env);
    return (0);
}
