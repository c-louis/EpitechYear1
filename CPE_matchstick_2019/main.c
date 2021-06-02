/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick main file
*/

#include "my.h"

int check_args(char **av)
{
    int line;
    int back;

    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    for (int i = 0; av[2][i] != '\0'; i++)
        if (av[2][i] < '0' || av[2][i] > '9')
            return (84);
    line = my_getnbr(av[1]);
    back = my_getnbr(av[2]);
    if (line < 2 || line > 99)
        return (84);
    if (!(back > 0))
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        my_printf("Arguments are not valid !\n");
        return (84);
    }
    if (check_args(av) == 84) {
        my_printf("Arguments are not valid !\n");
        return (84);
    }
    return (launch_matchstick(av));
}
