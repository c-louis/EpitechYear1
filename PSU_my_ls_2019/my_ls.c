/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls main function
*/

//TODO lRdrt + --help / -h

#include <stdbool.h> 
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>

#include "my.h"

int simple_ls(void)
{
    DIR *directory = opendir(".");
    struct dirent *file = readdir(directory);
    while (file != NULL) {
        if (file->d_name[0] != '.')
            my_printf("%s  ", file->d_name);
        file = readdir(directory);
    }
    closedir(directory);
    my_printf("\b\b\n");
    return (0);
}

int get_list_size(char **list)
{
    int i = 0;
    while (list[i] != NULL) {
        i++;
    }
    return (i);
}

void add_arg(char *arg, char **args)
{
    for (int i = 1; i < my_strlen(arg); i++) {
        if (arg[i] != 'R' && arg[i] != 'r'
            && arg[i] != 't' && arg[i] != 'h' && arg[i] != 'd' && arg[i] != 'l') {
            my_printf("ls: invalid option -- '%c'\n", arg[i]);
            my_printf("Try: 'ls -h' for more information.\n");
            exit(84);
        }
        char **args_new = malloc(sizeof(char *) * (i + 2));
        for (int y = 0; y < get_list_size(args); i++)
            args_new[y] = args[i];
        args_new[i] = arg;
        args_new[i+1] = NULL;
        free(args);
        args = args_new;
    }
}

int main(int ac, char **av)
{
    char **dirs;
    char **args = malloc(sizeof(char *) * 1);
    args[0] = NULL;

    if (ac == 1)
        return (simple_ls());
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            add_arg(av[i], args);
        } else {
            //add_dir(av[i], dirs);
        }
    }
    /*if (check_args(args) == 84)
        return (84);
    */
}
