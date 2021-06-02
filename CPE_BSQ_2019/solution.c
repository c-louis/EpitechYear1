/*
** EPITECH PROJECT, 2019
** solution
** File description:
** solution manging
*/

#include "bsq.h"
#include "bsq_struct.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void show_map(gbsq_t *gl)
{
    char **map = gl->map;
    for (int i = 0; map[i] != 0; i++) {
        write(1, map[i], gl->column);
        write(1, "\n", 1);
    }
}

void replace_solution(solution_t *soluce, gbsq_t *gl)
{
    char **map = gl->map;
    int row_s = soluce->row_start;
    int column_s = soluce->column_start;
    int size = soluce->size;
    for (int i = row_s; i < row_s+size; i++) {
        for (int y = column_s; y < column_s+size; y++) {
            map[i][y] = 'x';
        }
    }
    show_map(gl);
}

void find_solution(solution_t **solutions, gbsq_t *gl)
{
    solution_t *soluce = malloc(sizeof(solution_t) * 1);
    if (solutions[0] == 0) {
        show_map(gl);
        return;
    }
    soluce = solutions[0];
    for (int i = 0; solutions[i] != 0; i++) {
        if (soluce->size < solutions[i]->size)
            soluce = solutions[i];
    }
    replace_solution(soluce, gl);
}

int check_newrow(int size, int start_row, int start_column, gbsq_t *gl)
{
    char **map = gl->map;
    if (start_row >= gl->row)
        return (1);
    for (int i = start_column; i < start_column + size; i++) {
        if (map[start_row][i] == '\0' || map[start_row][i] == 'o')
            return (1);
    }
    return (0);
}

int check_end(int size, int start_row, int start_column, gbsq_t *gl)
{
    char **map = gl->map;
    for (int i = start_row; i < start_row + size; i++) {
        if (map[i] == 0 || start_column + size > gl->column)
            return (1);
        if (map[i][start_column+size] == 'o'
            || map[i][start_column+size] == '\0')
            return (1);
    }
    return (0);
}
