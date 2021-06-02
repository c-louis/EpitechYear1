/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** command/error check if a command has an error
*/

#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "shell.h"

void sanitalize_command(char const *cmd, char *new_cmd)
{
    int save_i = 0;
    int pos = 0;

    for (int i = 0; cmd && cmd[i]; i++) {
        if (!is_pipe_redirection(cmd[i])) {
            new_cmd[pos++] = cmd[i];
            continue;
        }
        for (save_i = i--; i >= 0 && is_space(cmd[i]); i--, pos--);
        for (i = save_i; cmd[i] && is_pipe_redirection(cmd[i]); i++)
            new_cmd[pos++] = cmd[i];
        for (; cmd[i] && is_space(cmd[i]); i++);
        i--;
    }
    new_cmd[pos] = 0;
}

char *sanitalize_complex_command(char *cmd)
{
    int space_c = 0;
    char *new_cmd;
    int save_i = 0;

    for (int i = 0; cmd && cmd[i]; i++) {
        if (!is_pipe_redirection(cmd[i]))
            continue;
        for (save_i = i--; i >= 0 && is_space(cmd[i]); i--, space_c++);
        for (i = save_i; cmd[i] && is_pipe_redirection(cmd[i]); i++);
        for (; cmd[i] && is_space(cmd[i]); i++, space_c++);
    }
    if (space_c == 0)
        return (cmd);
    new_cmd = malloc(my_strlen(cmd)- space_c + 1);
    if (!new_cmd)
        return (0);
    sanitalize_command(cmd, new_cmd);
    return (new_cmd);
}