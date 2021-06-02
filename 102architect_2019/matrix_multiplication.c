/*
** EPITECH PROJECT, 2019
** matrix
** File description:
** matrix_multiplication
*/

#include <stdlib.h>
#include <math.h>
#include "matrix.h"

void utils_multiply(matrix_t *mat_a, matrix_t *mat_b, matrix_t *result, int i)
{
    for (int y = 0; y < result->width; y++) {
        result->matrix[i][y] = 0;
        for (int k = 0; k < mat_a->width; k++) {
            result->matrix[i][y] +=
                (mat_a->matrix[i][k] * mat_b->matrix[k][y]);
        }
    }
}

matrix_t *multiply_matrix(matrix_t *mat_a, matrix_t *mat_b)
{
    if (mat_a->width != mat_b->height)
        return (NULL);
    matrix_t *result = create_matrix(mat_a->height, mat_b->width);
    for (int i = 0; i < result->height; i++) {
        utils_multiply(mat_a, mat_b, result, i);
    }
    return (result);
}

void multiply_and_copy(matrix_t *mat_a, matrix_t *mat_b)
{
    matrix_t *tmp_res = multiply_matrix(mat_a, mat_b);

    copy_matrix(tmp_res, mat_b);
    free_matrix(tmp_res);
    free_matrix(mat_a);
}
