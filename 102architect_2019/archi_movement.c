/*
** EPITECH PROJECT, 2019
** archi
** File description:
** archi_movement function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

matrix_t *translation(double i, double y)
{
    matrix_t *mat = create_matrix(3, 3);

    make_identity(mat);
    mat->matrix[0][2] = i;
    mat->matrix[1][2] = y;
    printf("Translation along vector (%d, %d)\n", (int) i, (int) y);
    return (mat);
}

matrix_t *scaling(double i, double y)
{
    matrix_t *mat = create_matrix(3, 3);

    make_identity(mat);
    mat->matrix[0][0] = i;
    mat->matrix[1][1] = y;
    printf("Scaling by factors %d and %d\n", (int) i , (int) y);
    return (mat);
}

matrix_t *rotation(double i)
{
    matrix_t *mat = create_matrix(3, 3);

    printf("Rotation by a %d degree angle\n", (int) i);
    make_identity(mat);
    i = (i*M_PI)/180;
    mat->matrix[0][0] = cosf(i);
    mat->matrix[0][1] = -sinf(i);
    mat->matrix[1][0] = sinf(i);
    mat->matrix[1][1] = cosf(i);
    return (mat);
}

matrix_t *reflexion(double i)
{
    matrix_t *mat = create_matrix(3, 3);

    printf("Reflection over an axis with an inclination angle of %d degrees\n",
        (int) i);
    make_identity(mat);
    i = (i*M_PI)/180;
    mat->matrix[0][0] = cos(2*i);
    mat->matrix[0][1] = sin(2*i);
    mat->matrix[1][0] = sin(2*i);
    mat->matrix[1][1] = -cos(2*i);
    return (mat);
}
