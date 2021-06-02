/*
** EPITECH PROJECT, 2019
** game
** File description:
** game handling function
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

void draw_map(gsoko_t *gl)
{
    for (int i = 0; i < gl->row; i++) {
        printw("%s\n", gl->map[i]);
    }
}

void reset(gsoko_t *gl)
{
    gl->map = make_map(gl->smap, gl);
}

void handle_movement(gsoko_t *gl, int key)
{
    if (key == KEY_DOWN)
        move_down(gl);
    if (key == KEY_UP)
        move_up(gl);
    if (key == KEY_LEFT)
        move_left(gl);
    if (key == KEY_RIGHT)
        move_right(gl);
    if (key == 32)
        reset(gl);
}

void handle_solution(gsoko_t *gl)
{
    int resolve = 0;
    int solution_count = 0;
    char **map = gl->map;
    for (int i = 0; gl->soluce[i] != NULL; i++) {
        solution_t *solution = gl->soluce[i];
        if (map[solution->x][solution->y] == 'X') {
            resolve++;
        } else if (map[solution->x][solution->y] == ' ') {
            map[solution->x][solution->y] = 'O';
        }
        solution_count++;
    }
    if (resolve == solution_count)
        gl->state = 2;
}

void handle_defeat(gsoko_t *gl)
{
    int count_cross = 0;
    int blocked = 0;
    for (int i = 0; i < my_strlen(gl->smap); i++)
        if (gl->smap[i] == 'X')
            count_cross++;
    for (int i = 0; i < gl->row; i++) {
        for (int y = 0; y < my_strlen(gl->map[i]); y++) {
            if (gl->map[i][y] != 'X')
                continue;
            if ((gl->map[i-1][y] == '#' || gl->map[i+1][y] == '#') &&
                (gl->map[i][y-1] == '#' || gl->map[i][y+1] == '#')) {
                blocked++;
            }
        }
    }
    if (blocked == count_cross)
        gl->state = 1;
}
