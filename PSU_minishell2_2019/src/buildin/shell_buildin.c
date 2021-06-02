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

int buildin_env(char ***env_ad)
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

int is_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i == 0 && str[i] == '-' && str[i + 1])
            continue;
        if (str[i] > '9' || str[i] < '0')
            return (0);
    }
    return (1);
}

int buildin_exit_code(char **cmd, int *end)
{
    if (!cmd[1]) {
        *end = 1;
        return (0);
    }
    if (cmd[1] && cmd[2]) {
        my_printf("exit: Expression Syntax.\n");
        return (1);
    }
    if (cmd[1] && is_numeric(cmd[1])) {
        *end = 1;
        return (my_getnbr(cmd[1]));
    }
    if (cmd[1] && ((cmd[1][0] >= '0' && cmd[1][0] <= '9')
        || (cmd[1][0] == '-' && cmd[1][1]))) {
        my_printf("exit: Badly formed number.\n");
        return (1);
    }
    my_printf("exit: Expression Syntax.\n");
    return (1);
}

int exec_buildin(char **cmd, char ***env, int *end)
{
    if (my_strcmp(cmd[0], "exit") == 0) {
        buildin_exit();
        return (buildin_exit_code(cmd, end));
    }
    if (my_strcmp(cmd[0], "setenv") == 0) {
        return (buildin_setenv(cmd, env));
    }
    if (my_strcmp(cmd[0], "unsetenv") == 0) {
        return (buildin_unsetenv(cmd, env));
    }
    if (my_strcmp(cmd[0], "env") == 0)
        return (buildin_env(env));
    if (my_strcmp(cmd[0], "cd") == 0)
        return (buildin_cd(cmd, env));
    return (-5000);
}
