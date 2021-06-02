/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** comamnd redirection
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

int redirect_right(cmd_t *list, char ***env, int *end, int index)
{
    int fd;
    int save_out;
    int status;

    if (list->action[index] == 4)
        fd = open(list->cmd[index + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    else
        fd = open(list->cmd[index + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
    if (fd == -1)
        return (1);
    save_out = dup(1);
    if (save_out == -1 || dup2(fd, 1) == -1)
        return (1);
    status = exec_single_command(list->cmd[index], env, end, 1);
    if (dup2(save_out, 1) == -1)
        return (1);
    close(fd);
    close(save_out);
    return (status);
}

int redirect_left(cmd_t *list, char ***env, int *end, int index)
{
    int fd;
    int save_in;
    int status = 0;

    if (list->action[index] == 2)
        fd = open(list->cmd[index + 1], O_RDONLY);
    else
        fd = -1;
    if (fd == -1)
        return (1);
    save_in = dup(0);
    if (save_in == -1 || dup2(fd, 0) == -1)
        return (1);
    status = exec_single_command(list->cmd[index], env, end, 1);
    close(fd);
    if (dup2(save_in, 0) == -1)
        return (1);
    close(save_in);
    return (status);
}

int shell_pipe(cmd_t *list, char ***env, int *end, int index)
{
    int fd[2];
    int status;

    if (pipe(fd) == -1)
        return (1);
    int out = dup(1);
    if (dup2(fd[1], 1) == -1)
        return (1);
    status = exec_single_command(list->cmd[index], env, end, 1);
    if (dup2(fd[0], 0) == -1)
        return (1);
    if (dup2(out, 1) == -1)
        return (1);
    close(fd[1]);
    return (status);
}