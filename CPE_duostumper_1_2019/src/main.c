/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** main
*/

#include "my.h"
#include "project.h"

#include <stddef.h>
#include <unistd.h>

void check_args(int ac, char **av, struct options *opt, char ***str)
{
    for (int i = 1; i < ac; i++) {
        if (is_arg(av[i], opt)) {
            handle_arg_bool(opt, av, i);
            handle_arg_num(opt, av, i);
        } else {
            add_path(str, av[i]);
        }
    }
}

int path_count(int ac, char **av)
{
    int count = 0;

    for (int i = 1; i < ac; i++)
        if (*av[i] != '-' && (*av[i] < '0' || *av[i] > '9'))
            count++;
    return count;
}

void tail_whil(void)
{
    while (1) {
        while (!read(0, NULL, 0));
        my_printf("\n");
    }
}

int main(int ac, char **av)
{
    struct options opt;
    char **str = NULL;

    opt.bytes = -1;
    opt.lines = 10;
    opt.quiet = 1;
    opt.start = 0;
    if (!path_count(ac, av))
        tail_whil();
    if (path_count(ac, av) >= 2)
        opt.quiet = 0;
    check_args(ac, av, &opt, &str);
    if (opt.ret == 1)
        return 1;
    tail(&opt, str);
    return opt.ret;
}
