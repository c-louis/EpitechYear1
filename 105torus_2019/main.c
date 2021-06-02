/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** torus main
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

int check_error(int ac, char **av)
{
    if (ac != 8)
        return (1);
    for (int i = 2; i < 8; i++)
        if (!is_double(av[i]))
            return (1);
    int preci = atoi(av[7]);
    if (preci <= 0)
        return (1);
    return (0);
}

int main_torus(int ac, char **av)
{
    if (check_error(ac, av))
        return (84);
    if (atoi(av[1]) == 1) {
        bisection(ac, av);
        return (0);
    }
    if (atoi(av[1]) == 2) {
        newton(ac, av);
        return (0);
    }
    if (atoi(av[1]) == 3) {
        secant(ac, av);
        return (0);
    }
    return (84);
}

void print_help(void)
{
    printf("USAGE\n\t./105torus ");
    printf("opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n\topt\tmethod option:\n");
    printf("\t\t\t1 for the bisection method\n");
    printf("\t\t\t2 for the Newton's method\n");
    printf("\t\t\t3 for the secant method\n");
    printf("\ta[0-4]\tcoefficients of the equation\n");
    printf("\tn\tprecision (the application of the polynomial to the");
    printf("solution should\n\t\tbe smaller than 10^-n)\n");
}

int main(int ac, char **av)
{
    if (ac == 8) {
        return (main_torus(ac, av));
    } else {
        if (ac == 2 && strcmp(av[1], "-h") == 0) {
            print_help();
            return (0);
        }
        return (84);
    }
}
