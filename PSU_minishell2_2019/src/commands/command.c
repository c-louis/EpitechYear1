/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** shell_command
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

int exec_complex_command(cmd_t *list, char ***env, int *end, int save[2])
{
    int command_c = 0;
    int status = 0;

    for (int i = 0; list->cmd[i]; i++, command_c++);
    for (int i = 0; i < command_c; i++) {
        if (list->cmd[i + 1] && (list->action[i] == 3 || list->action[i] == 4))
            status = redirect_right(list, env, end, i);
        if (list->cmd[i + 1] && (list->action[i] == 2 || list->action[i] == 1))
            status = redirect_left(list, env, end, i);
        if (list->cmd[i + 1] && list->action[i] == 5)
            status = shell_pipe(list, env, end, i);
        if (!list->cmd[i + 1]) {
            dup2(save[1], 1);
            status = exec_single_command(list->cmd[i], env, end, 1);
        }
        if (list->cmd[i + 1] && (list->action[i] >= 2 && list->action[i] != 5))
            i++;
    }
    free_cmd(list);
    return (status);
}

int handle_complex_command(char *cmd, char ***env, int *end)
{
    int fd[2];
    int status;

    if (!is_complex_command(cmd))
        return (exec_single_command(cmd, env, end, 1));
    cmd = sanitalize_complex_command(cmd);
    cmd_t *cmd_list = parse_command(cmd);
    if (!cmd_list)
        return (1);
    fd[0] = dup(0);
    fd[1] = dup(1);
    status = exec_complex_command(cmd_list, env, end, fd);
    if (dup2(fd[0], 0) == -1)
        return (1);
    if (dup2(fd[1], 0) == -1)
        return (1);
    return (status);
}

int handle_command(char *cmd, char ***env, int *end)
{
    char **cmd_list;
    int status = 0;

    cmd_list = preprocess(cmd, env);
    if (!cmd_list)
        return (1);
    if (raise_error(cmd_list))
        return (1);
    for (int i = 0; cmd_list[i]; i++)
        status = handle_complex_command(cmd_list[i], env, end);
    free_array(cmd_list);
    return (status);
}

char **preprocess(char *cmd, char ***env)
{
    char **cmd_list;
    int cmd_c = 0;

    for (int i = 0; cmd[i]; i++)
        if (cmd[i] == ';')
            cmd_c++;
    cmd_list = get_command_list(cmd, cmd_c);
    for (int i = 0; cmd_list[i]; i++) {
        cmd_list[i] = set_all_environment(cmd_list[i], env);
        if (cmd_list[i] == NULL)
            return (NULL);
    }
    return (cmd_list);
}