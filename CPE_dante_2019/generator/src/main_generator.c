/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main_generator
*/

#include "my.h"
#include "dante.h"

int is_perfect(int ac, char **av)
{
    if (ac == 3)
        return (0);
    else if ((ac == 4) && !my_strcmp(av[3], "perfect"))
        return (1);
    else
        return (1);
}

int verify_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_num(str[i]))
            return (-1);
    }
    return (0);
}

int error_handle(int ac, char **av)
{
    if (ac <= 2 || ac >= 5)
        return (-1);
    for (int i = 1; i < 3; i++) {
        if (verify_number(av[i]))
            return (-1);
    }
    if (is_perfect(ac, av) == -1) {
        return (-1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (error_handle(ac, av))
        return (84);
    else if (start_generator(ac, av))
        return (84);
    return (0);
}