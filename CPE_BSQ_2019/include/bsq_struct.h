/*
** EPITECH PROJECT, 2019
** header for struct
** File description:
** header for struct of the bsq
*/

typedef struct solution {
    int row_start;
    int column_start;
    int size;
} solution_t;

typedef struct globals_bsq {
    int row;
    int column;
    char *string_map;
    char **map;
    solution_t **solution;
} gbsq_t;
