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

int execute(char *path, char **arg, char **env, int wait)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid) {
        if (wait)
            waitpid(pid, &status, 0);
        if (path != arg[0]) free(path);
        handle_status(status, path);
        return (WEXITSTATUS(status));
    }
    status = execve(path, arg, env);
    if (status  == -1) {
        write(2, path, my_strlen(path));
        write(2, ": Permission denied.\n", 21);
        exit(1);
    }
    return (status);
}

int exec_command(char **arg, char **env, int is_local, int wait)
{
    char *path = NULL;
    int status = 0;

    if (is_local)
        path = arg[0];
    else if (access(arg[0], F_OK) != -1)
        path = arg[0];
    else
        path = find_path(arg, env);
    if (path == NULL && my_printf("%s: Command not found.\n", arg[0]))
        return (1);
    if (check_execution(path, arg[0]) == -1)
        return (1);
    status = execute(path, arg, env, wait);
    return (status);
}

int exec_single_command(char *cmd , char ***env, int *end, int wait)
{
    char **command_arg;
    int status = my_strlen(cmd);

    cmd[status - 1] = cmd[status - 1] == '\n' ? '\0' : cmd[status - 1];
    command_arg = my_str_to_args_array(cmd);
    if (command_arg == NULL)
        return (0);
    if (command_arg[0] == NULL || command_arg[0][0] == '\0')
        status = 0;
    else
        status = exec_buildin(command_arg, env, end);
    if (status == -5000) {
        status = my_strncmp(cmd, "./", 2) == 0 ? 1 :
            my_strncmp(cmd, "../", 3) == 0 ? 1 : 0;
        status = exec_command(command_arg, *env, status, wait);
    }
    free_array(command_arg);
    return (status);
}
