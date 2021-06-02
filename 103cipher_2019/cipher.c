/*
** EPITECH PROJECT, 2019
** cipher
** File description:
** cipher main file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "matrix.h"

int get_key_size(char *key)
{
    int size_2 = strlen(key) - 4;
    int x = 0;
    if (size_2 > 0)
        x = 3;
    else
        x = 2;
    return (x);
}

void fill_matrix(matrix_t *matrix_key, char *key)
{
    int x = 0;
    int y = 0;
    int max = (matrix_key->width * matrix_key->height);
    for (int i = 0; i < strlen(key) && i < max; i++) {
        int to_insert = key[i];
        matrix_key->matrix[x][y] = to_insert;
        if (y == matrix_key->width-1) {
            y = -1;
            x++;
        }
        y++;
    }
}

matrix_t *inverse_matrix(matrix_t *to_inverse)
{
    matrix_t *inverse = create_matrix(to_inverse->width, to_inverse->width);
    make_identity(inverse);
    //TODO INVERSE
}

void display_matrix_line(matrix_t *mat)
{
    for (int i = 0; i < mat->height; i++) {
        for (int y = 0; y < mat->width; y++) {
            printf("%.0f", mat->matrix[i][y]);
            if (!(i == mat->height-1 && y == mat->width-1))
                printf(" ");
        }
    }
    printf("\n");
}

void encrypt(char *str, char *key)
{
    int x = get_key_size(key);
    matrix_t *matrix_key = create_matrix(x, x);
    fill_matrix(matrix_key, key);
    int height = 0;
    while (height * matrix_key->width < strlen(str)) {
        height++;
    }
    matrix_t *matrix_str = create_matrix(height, x);
    fill_matrix(matrix_str, str);
    matrix_t *result = multiply_matrix(matrix_str, matrix_key);
    printf("Key matrix:\n");
    display_matrix(matrix_key);
    printf("\nEncrypted message:\n");
    display_matrix_line(result);
}

void decrypt(char *str, char *key)
{
    
}

void print_help(void)
{
    printf("USAGE\n\t./103cipher message key flag\n\n");
    printf("DESCRIPTION\n\tmessage\ta message, made of ASCII characters");
    printf("\n\tkey\tthe encryption key, made of ASCII characters\n\t");
    printf("flag\t 0 for the message to be encrypted, 1 to be decrypted\n");
}

int main(int ac, char **av)
{
    if (ac == 4) {
        char *str = av[1];
        char *key = av[2];
        int mode = atoi(av[3]);
        if (mode == 0) {
            encrypt(str, key);
        } else if (mode == 1) {
            decrypt(str, key);
        } else {
            return (84);
        }
    } else {
        if (ac == 2 && strcmp(av[1], "-h") == 0)
            print_help();
        if (ac < 4 || ac > 4)
            return (84); 
    }
}
