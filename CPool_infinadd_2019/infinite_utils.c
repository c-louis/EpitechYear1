/*
** EPITECH PROJECT, 2019
** infin utils function
** File description:
** all utils functions
*/

#include "my.h"
#include "infinite.h"

void remove_minus(char **av)
{
    if (av[1][0] == '-')
        av[1] = av[1] + 1;
    if (av[2][0] == '-')
        av[2] = av[2] + 1;
}

int is_result_neg(char **av)
{
    int length = my_strlen(av[1]) - my_strlen(av[2]);
    length = (av[1][0] == '-') ? length - 1 : length + 1;
    if ((length < 0 && av[1][0] == '-') || (av[1][0] != '-' && length > 0))
        return (0);
    if ((length > 0 && av[1][0] == '-') || (av[1][0] != '-' && length < 0))
        return (1);
    if (length == 0) {
        for (int i = 0; i < my_strlen(av[1]); i++) {
            remove_minus(av);
            if (av[1][i] == '-' || av[2][i] == '-') {
                continue;
            }
            if ((av[1][i] < av[2][i] && av[1][0] == '-')
                || (av[1][i] > av[2][i] && av[2][0] == '-'))
                return (0);
            if ((av[1][i] > av[2][i] && av[1][0] != '-')
                || (av[1][i] < av[2][i] && av[2][0] != '-'))
                return (1);
        }
    }
    return (0);
}

void my_memset(char *str, int max)
{
    int i = 0;
    while (i < max + 1) {
        str[i] = '0';
        i++;
    }
    str[max + 1] = '\0';
}

int compare_number(char **avmaria)
{
    char **av = avmaria;
    if ((av[1][0] == '-' && my_strlen(av[1]) - 1 > my_strlen(av[2]))
        || (av[2][0] == '-' && my_strlen(av[2]) - 1 < my_strlen(av[1])))
        return (1);
    if ((av[1][0] == '-' && my_strlen(av[1]) - 1 < my_strlen(av[2]))
        || (av[2][0] == '-' && my_strlen(av[2]) - 1 > my_strlen(av[1])))
        return (-1);
    if ((av[1][0] == '-' && my_strlen(av[1]) - 1 == my_strlen(av[2]))) {
        remove_minus(av);
        for (int i = 0; i < my_strlen(av[1]); i++) {
            if (av[1][i] > av[2][i]) return (1);
        }
        return (-1);
    }
    if ((av[2][0] == '-' && my_strlen(av[2]) - 1 == my_strlen(av[1]))) {
        remove_minus(av);
        for (int i = 0; i < my_strlen(av[1]); i++) {
            if (av[1][i] > av[2][i]) return (1); }
        return (-1);
    } return (84);
}

int determine_operation(char **av)
{
    int is_neg = 0;
    if ((av[1][0] != '-' && av[2][0] != '-')
        || (av[1][0] == '-' && av[2][0] == '-')) {
        handle_number(av, is_neg, 1, 0);
        return (0);
    }
    if ((av[1][0] == '-' && av[2][0] != '-')
        || (av[1][0] != '-' && av[2][0] == '-')) {
        is_neg = is_result_neg(av);
        int cmp = compare_number(av);
        if (cmp > 0)
            handle_number(av, is_neg, 0, 0);
        if (cmp < 0)
            handle_number(av, is_neg, 0, 1);
    } return (0);
}
