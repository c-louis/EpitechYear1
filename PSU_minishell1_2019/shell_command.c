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

void handle_status(int status)
{
    char *error;

    if (status != 0 && status < 65) {
        error = strsignal(status);
        write(2, error, my_strlen(error));
        write(2, "\n", 1);
    }
}

int check_execution(char *path)
{
    if (access(path, X_OK) != -1)
        return (0);
    perror(path);
    return (-1);
}

int exec_command(char **arg, char **env)
{
    char *path = find_path(arg, env);
    int status = 0;
    pid_t pid;

    if (access(arg[0], F_OK) != -1) path = arg[0];
    if (path == NULL && my_printf("%s: Command not found.\n", arg[0]))
        return (0);
    if (check_execution(path) == -1) return (0);
    if ((pid = fork())) {
        waitpid(pid, &status, 0);
        if (path != arg[0]) free(path);
        handle_status(status);
        return (status);
    }
    if ((status = execve(path, arg, env)) == -1) {
        perror(path);
        exit(0);
    }
    free(path);
}

int handle_command(char *cmd, char ***env, int *end)
{
    char **command_arg;
    int status = my_strlen(cmd);

    cmd[status - 1] = cmd[status - 1] == '\n' ? '\0' : cmd[status - 1];
    command_arg = my_str_to_args_array(cmd);
    if (command_arg == NULL)
        return (0);
    if (command_arg[0] == NULL || command_arg[0][0] == '\0') {
        free(command_arg);
        return (0);
    }
    else if ((status = exec_buildin(command_arg, env, end)) != -1) {
        free_array(command_arg);
        return (status);
    } else {
        status = exec_command(command_arg, *env);
    }
    free_array(command_arg);
    return (status);
}
