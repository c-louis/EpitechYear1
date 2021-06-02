/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell_cd functions
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "shell.h"

void actualize_pwd(char **cmd, char ***env, char *oldpwd)
{
    char *pwd;
    char *buf = get_pwd();

    set_oldpwd(cmd, env, oldpwd);
    pwd = malloc(my_strlen(buf) + 5);
    pwd[0] = '\0';
    my_strcat(pwd, "PWD=");
    my_strcat(pwd, buf);
    remove_env("PWD", env);
    add_env(pwd, env);
    free(buf);
}

char *get_path(char **cmd, char ***env)
{
    char *path = NULL;
    if (cmd[1] == NULL) {
        path = get_env("HOME", *env);
        if (path != NULL)
            path += 5;
    } else if (my_strcmp(cmd[1], "-") == 0) {
        path = get_env("OLDPWD", *env);
        if (path != NULL)
            path += 7;
    } else {
        path = cmd[1];
    }
    return (path);
}

int buildin_cd(char **cmd, char ***env)
{
    char *path = get_path(cmd, env);
    char *pwd = get_pwd();

    if (path == NULL)
        return (0);
    if (cmd[1] != NULL && cmd[2] != NULL) {
        write(2, "cd: Too many arguments.\n", 24);
        return (1);
    }
    if (chdir(path) == 0)
        actualize_pwd(cmd, env, pwd);
    else {
        free(pwd);
        perror(path);
        return (1);
    }
}
