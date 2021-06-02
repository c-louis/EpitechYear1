/*
** EPITECH PROJECT, 2020
** calculation
** File description:
** calcul thing
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double equation(int ac, char **av, double x)
{
    double a0 = atof(av[2]);
    double a1 = x * atof(av[3]);
    double a2 = pow(x, 2) * atof(av[4]);
    double a3 = pow(x, 3) * atof(av[5]);
    double a4 = pow(x, 4) * atof(av[6]);
    double result = (a4+a3+a2+a1+a0);

    return (result);
}

double equation_prime(int ac, char **av, double x)
{
    double a4 = pow(x, 3) * atof(av[6]) * 4;
    double a3 = pow(x, 2) * atof(av[5]) * 3;
    double a2 = x * atof(av[4]) * 2;
    double a1 = atof(av[3]);
    double result = (a4+a3+a2+a1);

    return (result);
}

void bisection(int ac, char **av)
{
    double a = 0;
    double b = 1;
    double m = 0;
    int preci = 0;
    double e = atof(av[7]);
    while (b - a > pow(10, -1*(atoi(av[7])))) {
        m = (a + b) / 2;
        if (equation(ac, av, a) * equation(ac, av, m) <= 0)
            b = m;
        else
            a = m;
        if (preci < atoi(av[7]))
            preci++;
        printf("x = %.*f\n", preci, m);
    }
}

void newton(int ac, char **av)
{
    double x = 0.5;
    double x2 = 0.5;
    double prime = 0;
    double equa = 0;

    printf("x = 0.5\n");
    do {
        x = x2;
        equa = equation(ac, av, x);
        prime = equation_prime(ac, av, x);
        if (prime == 0)
            return;
        x2 = x - (equa / prime);
        if (fabs(x2 - x) < pow(10, -1*atoi(av[7])))
            return;
        printf("x = %.*f\n", atoi(av[7]), x2);
    } while (1);
}

void secant(int ac, char **av)
{
    double x = 0;
    double x1 = 1;
    double x2 = 0;
    int i = 0;
    while (1) {
        if ((x1 - x) == 0)
            return;
        if (((equation(ac, av, x1) - equation(ac, av, x)) / (x1 -x)) == 0)
            return;
        x2 = x1 - (equation(ac, av, x1) /
            ((equation(ac, av, x1) -
            equation(ac, av, x)) /
            (x1 - x)));
        x = x1;
        x1 = x2;
        printf("x = %.*f\n", (i++ == 0) ? 1 : atoi(av[7]), x2);
        if (fabs(x1 - x) < pow(10, -1*atoi(av[7])))
            return;
    }
}
