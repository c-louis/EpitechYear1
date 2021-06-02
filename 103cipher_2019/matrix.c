/*
** EPITECH PROJECT, 2019
** matrix
** File description:
** matrix handling
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

matrix_t *create_matrix(int height, int width)
{
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->height = height;
    mat->width = width;
    mat->matrix = malloc(sizeof(double *) * (height+1));
    for (int i = 0; i < height; i++) {
        double *line = malloc(sizeof(double) * (width+1));
        for (int y = 0; y < width; y++)
            line[y] = 0;
        mat->matrix[i] = line;
    }
    mat->matrix[height] = NULL;
    return (mat);
}

void free_matrix(matrix_t *mat)
{
    for (int i = 0; mat->matrix[i] != NULL; i++) {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    free(mat);
}

void make_identity(matrix_t *mat)
{
    if (mat->height != mat->width)
        return;
    for (int i = 0; i < mat->height; i++)
        mat->matrix[i][i] = 1;
}

void display_matrix(matrix_t *mat)
{
    for (int i = 0; i < mat->height; i++) {
        for (int y = 0; y < mat->width; y++) {
            printf("%-*.0f", (y+1 == mat->width) ? 1 : 8, mat->matrix[i][y]);
        }
        printf("\n");
    }
}

void copy_matrix(matrix_t *mat_a, matrix_t *mat_b)
{
    if (mat_a->height != mat_b->height || mat_a->width != mat_b->width)
        return;
    for (int i = 0; i < mat_a->height; i++) {
        for (int y = 0; y < mat_a->width; y++) {
            mat_b->matrix[i][y] = mat_a->matrix[i][y];
        }
    }
}
