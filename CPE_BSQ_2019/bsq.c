/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** bsq function
*/

#include "bsq.h"
#include "bsq_struct.h"
#include "my.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void find_bigger(solution_t *s, gbsq_t *gl)
{
    int size = s->size + 1;
    if (check_end(size-1, s->row_start, s->column_start, gl) == 1) {
        return;
    }
    if (check_newrow(size, s->row_start+(size-1), s->column_start, gl) == 1) {
        return;
    }
    s->size = size;
    find_bigger(s, gl);
}

int find_all_solution(gbsq_t *gl)
{
    char **map = gl->map;
    int solution_index = 0;
    int y = 0;
    for (int i = 0; i < gl->row; y++) {
        if (map[i][y] == '.') {
            solution_t *s = malloc(sizeof(solution_t));
            s->row_start = i;
            s->column_start = y;
            s->size = 1;
            find_bigger(s, gl);
            gl->solution[solution_index++] = s;
        }
        if (map[i][y] != 'o' && map[i][y] != '.' && map[i][y] != '\0')
            return (84);
        if (y >= gl->column) { i++;
            y = 0;
        }
    }
    gl->solution[solution_index] = 0;
    find_solution(gl->solution, gl);
}

char **make_map(char *m_map, gbsq_t *gl)
{
    char **map = malloc(sizeof(char *) * (gl->row+1));
    for (int i = 0; i < gl->row; i++) {
        char *to_add = malloc(sizeof(char) * (gl->column+1));
        for (int y = 0; y < gl->column; y++) {
            to_add[y] = m_map[(i*(gl->column+1)) + y];
        }
        to_add[gl->column] = '\0';
        map[i] = to_add;
    }
    map[gl->row] = 0;
    return (map);
}

void init_global(gbsq_t *gl, char *square)
{
    int row = my_getnbr(square);
    int nbsize = determine_nb_size(row);
    int column = 0;
    char *only_s = malloc(my_strlen(square) + 1);
    my_strcpy(only_s, square+(nbsize+2));
    only_s[my_strlen(square)] = '\0';
    for (int i = nbsize+2; square[i] != '\n' && square[i] != '\0'; i++) {
        column++;
    }
    gl->row = row;
    gl->column = column;
    gl->map = make_map(only_s, gl);
    gl->string_map = only_s;
    gl->solution = malloc(sizeof(solution_t *) * my_strlen(only_s));
}

int bsq(int ac, char **av)
{
    if (ac < 2) {
        return (84);
    } else {
        if (check_error(ac, av) == 84) {
            return (84);
        }
    }
    char *square = read_all(av[1]);
    gbsq_t *gl = malloc(sizeof(gbsq_t));
    init_global(gl, square);
    if (check_map_error(gl) == 84)
        return (84);
    find_all_solution(gl);
    free(square);
    free(gl);
    return (0);
}
