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

int redir_error(char first, char second)
{
    if (is_redirection(first) && is_pipe_redirection(second))
        my_printf("Missing name for redirect.\n");
    if ((is_pipe(first) && second == '>')
        || (is_pipe(first) && is_pipe(second)))
        my_printf("Invalid null command.\n");
    if (is_pipe(first) && second == '<')
        my_printf("Ambiguous input redirect.\n");
    return (1);
}

int check_command_error(char *cmd, int lwrp, char last, int rs)
{
    for (int i = 0; cmd[i]; i++) {
        if (!is_pipe_redirection(cmd[i]) && lwrp && !--lwrp)
            continue;
        else if (!is_pipe_redirection(cmd[i]) && !lwrp)
            continue;
        if (lwrp || !++lwrp)
            return (redir_error(last, cmd[i]));
        for (last = 0, rs = 0;is_pipe_redirection(cmd[i]); i++, rs++)
            if (!last)
                last = cmd[i];
            else if (last != cmd[i])
                return (redir_error(last, cmd[i]));
        if ((is_redirection(last) && rs > 2)
            || (is_redirection(last) && !cmd[i + 1]))
            return (redir_error('<', '<'));
        if ((is_pipe(last) && rs > 1) || (is_pipe(last) && !cmd[i + 1]))
            return (redir_error(last, last));
        for (;cmd[i] && is_space(cmd[i] && is_space(cmd[i + 1])); i++);
    }
    return (0);
}

int raise_error(char **cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (!is_complex_command(cmd[i]))
            continue;
        if (check_command_error(cmd[i], 0, 0, 0))
            return (1);
    }
    return (0);
}