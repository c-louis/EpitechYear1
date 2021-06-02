/*
** EPITECH PROJECT, 2020
** tail
** File description:
** tail error
*/

#include "my.h"
#include "project.h"

int print_err_open(char *path, struct options *opt)
{
    my_printf("tail: cannot open '%s' for reading:", path);
    my_printf(" No such file or directory\n");
    opt->ret = 1;
    return (84);
}

void print_verbose(char *path, struct options *opt)
{
    if (!opt->quiet)
        my_printf("==> %s <==\n", path);
}
