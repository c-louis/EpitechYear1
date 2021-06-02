/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** shell_preprocess function
*/

#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

char *get_env_name(char *str, int i)
{
    int y = i;
    char *env_name;

    for (;str[i] && str[i] != ' ' && str[i] != '\n'; i++);
    env_name = malloc(i - y + 1);
    env_name[0] = 0;
    my_strncat(env_name, str + y, i - y);
    env_name[i -y] = 0;
    return (env_name);
}

int check_environment_variable(char *str, int i, char ***env)
{
    int y = i;
    char *env_name;
    char *env_prop;

    for (; str[i] != '\0' && str[i] != ' ' && str[i] != '\n'; i++)
        if (!((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= '0' && str[i] <= '9'))) {
            my_printf("Illegal variable name.\n");
            return (1);
        }
    env_name = get_env_name(str, y);
    env_prop = get_env(env_name, *env);
    if (!env_prop) {
        my_printf("%s: Undefined variable.\n", env_name);
        free(env_name);
        return (1);
    }
    free(env_name);
    return (0);
}

char *set_environment(char *cmd, int i, char ***env)
{
    char *en;
    char *ep;
    char *new_cmd;

    en = get_env_name(cmd, i + 1);
    if (!en)
        return (0);
    ep = get_env(en, *env);
    new_cmd = malloc(my_strlen(cmd) - 2 * my_strlen(en) + my_strlen(ep));
    if (!new_cmd)
        return (NULL);
    new_cmd[0] = 0;
    my_strncat(new_cmd, cmd, i);
    my_strcat(new_cmd, ep + my_strlen(en) + 1);
    my_strcat(new_cmd, cmd + i + my_strlen(en) + 1);
    free_2(cmd, en);
    return (new_cmd);
}

char *set_all_environment(char *cmd, char ***env)
{
    for (int i = 0; cmd && cmd[i]; i++) {
        if (!(cmd[i] == '$'))
            continue;
        if (check_environment_variable(cmd, i+1, env))
            return (NULL);
        cmd = set_environment(cmd, i, env);
        i = 0;
    }
    return (cmd);
}

char **get_command_list(char *cmd, int cmd_c)
{
    char **cmd_list = malloc(sizeof(char *) * (cmd_c + 2));
    int y = 0;
    int last_y = 0;

    if (!cmd_list)
        return (NULL);
    cmd_list[cmd_c + 1] = NULL;
    for (int i = 0; i < cmd_c + 1; i++, y++) {
        last_y += y;
        for (y = 0; cmd[y + last_y] && cmd[y + last_y] != ';'
            && cmd[y + last_y] != '\n'; y++);
        cmd_list[i] = malloc(y + 1);
        if (!cmd_list[i])
            return (NULL);
        cmd_list[i][0] = '\0';
        my_strncat(cmd_list[i], cmd + last_y, y);
    }
    return (cmd_list);
}