/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** arg_handling
*/

#include "my.h"
#include "project.h"

int is_arg(char *str, struct options *opt)
{
    int len = my_strlen(str);

    if (len == 0)
        return 0;
    if (str[0] != '-')
        return 0;
    if (str[1] == '-')
        return 1;
    for (int i = 2; i < len; i++) {
        if (str[i] == '+' && i + 1 < len) {
            (*opt).start = 1;
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
            err_invalidarg(str, opt);
    }
    return 1;
}

int argcmp(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);

    if (str1_len - 2 != str2_len)
        return 0;
    for (int i = 0; i < str2_len; i++)
        if (str1[i + 2] != str2[i])
            return 0;
    return 1;
}

int handle_arg_bool(struct options *opt, char **av, int i)
{
    if (av[i][1] == 'q' || argcmp(av[i], "quiet") || argcmp(av[i], "silent")) {
        (*opt).quiet = 1;
        return 0;
    }
    if (av[i][1] == 'v' || argcmp(av[i], "verbose")) {
        (*opt).quiet = 0;
        return 0;
    }
    return 1;

}

int has_value(char **av, int i)
{
    if (!av[i + 1])
        return 0;
    return 1;
}

int handle_arg_num(struct options *opt, char **av, int i)
{
    if (av[i][1] == 'c' || argcmp(av[i], "bytes")) {
        (*opt).lines = -1;
        if (!av[i][2] && has_value(av, i))
            (*opt).bytes = my_getnbr(av[i + 1]);
        else if (av[i][2])
            (*opt).bytes = my_getnbr(av[i] + 2);
        else
            (*opt).ret = 1;
        return 0;
    }
    if (av[i][1] == 'n' || argcmp(av[i], "lines")) {
        (*opt).bytes = -1;
        if (!av[i][2] && has_value(av, i))
            (*opt).lines = my_getnbr(av[i + 1]);
        else if (av[i][2])
            (*opt).lines = my_getnbr(av[i] + 2);
        else
            (*opt).ret = 1;
        return 0;
    }
}
