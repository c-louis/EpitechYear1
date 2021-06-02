/*
** EPITECH PROJECT, 2019
** error
** File description:
** error handling
*/

#include "my.h"
#include "101pong.h"
#include <stdlib.h>

int check_float(char *arg)
{
    int virgule = 0;
    if (arg[0] == '-')
        arg = arg + 1;
    for (int i = 0; i < my_strlen(arg); i++) {
        if (arg[i] < '0' || arg[i] > '9') {
            if (arg[i] == '.' && virgule == 0) {
                virgule++;
                continue;
            }
            return (84);
        }
    }
    return (0);
}

int check_int(char *arg)
{
    for (int i = 0; i < my_strlen(arg); i++) {
        if (arg[i] < '0' || arg[i] > '9')
            return (84);
    }
    return (0);
}

void test_error(int ac, char **av)
{
    for (int i = 1; i < 7; i++) {
        if(check_float(av[i]) == 84)
            exit(84);
    }
    if (check_int(av[7]) == 84)
        exit(84);
}
