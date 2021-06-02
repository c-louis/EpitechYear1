/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** commands utils fonction check && error handling
*/

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "my.h"
#include "shell.h"

void free_cmd(cmd_t *cmd)
{
    for (int i = 0; cmd->cmd[i]; i++)
        free(cmd->cmd[i]);
    free(cmd->cmd);
    free(cmd->action);
    free(cmd);
}

void print_core_error(int status)
{
    if (status == 136 || status == SIGFPE)
        write(2, "Floating exception", 18);
    if (status == 139 || status == SIGSEGV)
        write(2, "Segmentation fault", 18);
    if (WCOREDUMP(status))
        write(2, " (core dumped)", 14);
    if (status == 136 || status == SIGFPE
        || status == 139 || status == SIGSEGV)
        write(2, "\n", 1);
}

void handle_status(int status, char *path)
{
    char *error;

    if (status == 2048) {
        write(2, path, my_strlen(path));
        write(2, ": Exec format error. ", 21);
        write(2, "Binary file not executable.\n", 28);
    }
    print_core_error(status);
}

int check_execution(char *path, char *arg)
{
    if (access(path, F_OK) == -1) {
        my_printf("%s: Command not found.\n", arg);
        return (-1);
    }
    if (access(path, F_OK) != -1 && access(path, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", arg);
        return (-1);
    }
    if (access(path, X_OK) != -1)
        return (0);
    my_printf("%s: Permission denied.\n", arg);
    return (-1);
}