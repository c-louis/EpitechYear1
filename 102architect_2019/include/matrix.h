/*
** EPITECH PROJECT, 2019
** matrix header
** File description:
** matrix header struct and function included
*/

typedef struct matrix {
    int height;
    int width;
    double **matrix;
} matrix_t;

matrix_t *create_matrix(int height, int width);
void free_matrix(matrix_t *mat);
void make_identity(matrix_t *mat);
void display_matrix(matrix_t *mat);
void copy_matrix(matrix_t *mat_a, matrix_t *mat_b);
matrix_t *multiply_matrix(matrix_t *mat_a, matrix_t *mat_b);
void multiply_and_copy(matrix_t *mat_a, matrix_t *mat_b);
