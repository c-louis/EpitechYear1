/*
** EPITECH PROJECT, 2019
** intersection function
** File description:
** functions
*/

#include <stdio.h>
#include <string.h>

int is_number(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

void print_help(void)
{
    printf("USAGE\n\t./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n\topt\t\tsurface option: 1 for a sphere,");
    printf(" 2 for a cylinder, 3 for a cone\n\t(xp, yp, zp)\t");
    printf("coordinates of a point by which the light ray passes through\n\t");
    printf("(xv, yv, zv)\tcoordinates of a vector parallel to the light ray");
    printf("\n\tp\t\tparameter: radious of the sphere, radius of the cylinder");
    printf(", or\n\t\t\tangle formed by the cone and the Z-axis\n");
}

int main(int ac, char **av)
{
    if (ac > 1 && strcmp(av[1], "-h") == 0)
        print_help();
    if (ac != 9)
        return (84);
    for (int i = 1; i < 9; i++) {
        if (is_number(av[i]) == 0)
            return (84);
    }
}
