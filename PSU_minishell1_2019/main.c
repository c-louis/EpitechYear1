/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** main_shell
*/

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

char *get_pwd(void)
{
    size_t size = 32;
    char *buf = malloc(size);

    while (getcwd(buf, size) == NULL) {
        free(buf);
        size *= 2;
        buf = malloc(size);
    }
    return (buf);
}

int shell(char ***shell_env)
{
    char *command = NULL;
    char *pwd;
    int read = 0;
    size_t len = 0;
    int end = 0;
    int status = 0;

    while (!end) {
        pwd = get_pwd();
        if (isatty(0))
            my_printf("%s $> ", pwd);
        free(pwd);
        read = getline(&command, &len, stdin);
        if (read == -1 && buildin_exit() == 0)
            return (status > 1 ? status + 128 : status);
        status = handle_command(command, shell_env, &end);
    }
    free(command);
    free_array(*shell_env);
    return (status > 1 ? status + 128 : status);
}

int main(int ac, char **av, char **env)
{
    int end = 0;
    char **shell_env = copy_env(env);

    return (shell(&shell_env));
}
