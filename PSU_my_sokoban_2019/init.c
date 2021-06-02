/*
** EPITECH PROJECT, 2019
** init
** File description:
** initialization function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void init_solution(gsoko_t *gl)
{
    int soluce_count = 0;
    int soluce_index = 0;
    for (int i = 0; i < my_strlen(gl->smap); i++) {
        if (gl->smap[i] == 'O')
            soluce_count++;
    }
    gl->soluce = malloc(sizeof(solution_t *) * (soluce_count +1));
    for (int i = 0; i < gl->row; i++) {
        for (int y = 0; y < my_strlen(gl->map[i]); y++) {
            if (gl->map[i][y] == 'O') {
                solution_t *new_solution = malloc(sizeof(solution_t));
                new_solution->x = i;
                new_solution->y = y;
                gl->soluce[soluce_index++] = new_solution;
            }
        }
    }
    gl->soluce[soluce_count] = NULL;
}

void init_soko(gsoko_t *gl, int ac, char **av)
{
    gl->smap = read_map(av[1]);
    gl->column = get_mapcolumn(gl->smap);
    gl->row = get_maprow(gl);
    gl->map = make_map(gl->smap, gl);
    gl->state = 0;
    init_solution(gl);
}

void set_ncurses_param(void)
{
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
}
