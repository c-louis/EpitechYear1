/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** shell_parsing
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

int count_command(char *cmd)
{
    int command_count = 1;

    for (int i = 0; cmd[i]; i++) {
        if (!is_pipe_redirection(cmd[i]))
            continue;
        for (; cmd[i] && is_pipe_redirection(cmd[i]); i++);
        command_count++;
    }
    return (command_count);
}

int get_action(char *cmd, int i)
{
    if (my_strncmp(cmd+i, "<<", 2) == 0)
        return (1);
    if (my_strncmp(cmd+i, ">>", 2) == 0)
        return (3);
    if (my_strncmp(cmd+i, "<", 1) == 0)
        return (2);
    if (my_strncmp(cmd+i, ">", 1) == 0)
        return (4);
    if (my_strncmp(cmd+i, "|", 1) == 0)
        return (5);
    return (-1);
}

void get_o_command_list(char *cmd, cmd_t *list, int command_count)
{
    int lgt = 0;
    int index = 0;
    int start_i = 0;

    for (int i = 0; cmd[i]; i++) {
        start_i = i;
        for (lgt = 0; cmd[i] && !is_pipe_redirection(cmd[i]); i++, lgt++);
        list->cmd[index] = malloc(lgt + 1);
        list->cmd[index][0] = 0;
        list->cmd[index] = my_strncat(list->cmd[index], cmd + start_i, lgt);
        if (command_count - 1 != index)
            list->action[index++] = get_action(cmd, i);
        for (; cmd[i] && is_pipe_redirection(cmd[i]); i++);
        i--;
    }
}

int check_action(cmd_t *list, int command_count)
{
    for (int i = 0; i < command_count - 2; i++)
        if ((list->action[i] == 3 || list->action[i] == 4)
            && (list->action[i + 1] >= 3)) {
                my_printf("Ambiguous output redirect.\n");
                return (1);
        }
    return (0);
}

cmd_t *parse_command(char *cmd)
{
    int command_count = count_command(cmd);
    cmd_t *list = malloc(sizeof(cmd_t));

    if (!list)
        return (0);
    list->cmd = malloc(sizeof(char *) * (command_count + 1));
    list->action = malloc(sizeof(int) * (command_count - 1));
    if (!list->cmd || !list->action)
        return (0);
    list->cmd[command_count] = 0;
    get_o_command_list(cmd, list, command_count);
    if (check_action(list, command_count)) {
        free_cmd(list);
        return (0);
    }
    free(cmd);
    return (list);
}