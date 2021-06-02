/*
** EPITECH PROJECT, 2019
** checker
** File description:
** checker functions
*/

#include <string.h>

int is_double(char *arg)
{
    int i = 0;
    int virg = 0;
    if (arg[0] == '-' && arg[1] != '\0')
        i++;
    if (arg[i] == '.')
        return (0);
    for (i; i < strlen(arg); i++) {
        if (virg == 0 && arg[i] == '.') {
            virg++;
            continue;
        }
        if (virg == 1 && arg[i] == '.')
            return (0);
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
    }
    return (1);
}

int check_args(int ac, char **av)
{
    int double_to_check = 2;
    for (int i = 1; i < ac; i++) {
        if (double_to_check > 0 && is_double(av[i]) == 0) {
            return (84);
        } else if (double_to_check > 0) {
            double_to_check--;
            continue;
        }
        if (double_to_check == 0 && is_double(av[i]))
            return (84);
        if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0) {
            double_to_check = 2;
        }
        if (strcmp(av[i], "-r") == 0 || strcmp(av[i], "-s") == 0) {
            double_to_check = 1;
        }
    }
    if (double_to_check > 0)
        return (84);
    return (0);
}
