/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** command checker function (simple verification)
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

int is_redirection(char c)
{
    if (c == '>' || c == '<')
        return (1);
    return (0);
}

int is_pipe(char c)
{
    if (c == '|')
        return (1);
    return (0);
}

int is_pipe_redirection(char c)
{
    if (is_pipe(c) || is_redirection(c))
        return (1);
    return (0);
}

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int is_complex_command(char *cmd)
{
    int is_complex = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '>')
            is_complex = 1;
        if (cmd[i] == '<')
            is_complex = 2;
        if (cmd[i] == '|')
            is_complex = 3;
    }
    return (is_complex);
}