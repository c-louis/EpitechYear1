/*
** EPITECH PROJECT, 2019
** architect
** File description:
** architect main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "archi.h"

void print_help(void)
{
    printf("USAGE\n");
    printf("\t./102architect x y");
    printf(" transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\n");
    printf("DESCRIPTION\n");
    printf("\tx\tabsissa of the original point\n");
    printf("\ty\tordinate of the original point\n\n");
    printf("\ttransfo arg1 [arg2]\n");
    printf("\t-t i j  translation along vector (i, j)\n");
    printf("\t-z m n  scaling by factors m (x-axis) and n (y-axis)\n");
    printf("\t-r d    rotation centered in O by a d degree angle\n");
    printf("\t-s d    reflection over the axis passing through O ");
    printf("with an inclination\n\t\tangle of d degrees\n");
}

matrix_t *get_transformation(int ac, char **av)
{
    matrix_t *result = create_matrix(3, 3);
    matrix_t *cop = NULL;
    make_identity(result);
    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-t") == 0 && av[i+1] != 0 && av[i+2] != 0)
            cop = translation(atof(av[i+1]), atof(av[i+2]));
        if (strcmp(av[i], "-z") == 0 && av[i+1] != 0 && av[i+2] != 0)
            cop = scaling(atof(av[i+1]), atof(av[i+2]));
        if (strcmp(av[i], "-r") == 0 && av[i+1] != 0)
            cop = rotation(atof(av[i+1]));
        if (strcmp(av[i], "-s") == 0 && av[i+1] != 0)
            cop = reflexion(atof(av[i+1]));
        if (cop != NULL) {
            multiply_and_copy(cop, result);
            cop = NULL;
        }
    }
    return (result);
}

int do_archi(int ac, char **av)
{
    double x = atof(av[1]);
    double y = atof(av[2]);
    matrix_t *point = create_matrix(3, 1);
    matrix_t *result = get_transformation(ac, av);

    point->matrix[0][0] = x;
    point->matrix[1][0] = y;
    point->matrix[2][0] = 1;
    matrix_t *point_res = multiply_matrix(result, point);
    display_matrix(result);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y,
        point_res->matrix[0][0], point_res->matrix[1][0]);
    free_matrix(result);
    free_matrix(point);
    free_matrix(point_res);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    int c = 0;
    if (check_args(ac, av) != 0) {
        return (84);
    }
    if (ac > 2) {
        c = do_archi(ac, av);
    }
    return (c);
}
