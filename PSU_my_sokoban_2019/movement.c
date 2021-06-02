/*
** EPITECH PROJECT, 2019
** movement
** File description:
** movement function
*/

#include "my.h"
#include "sokoban.h"

void move_down(gsoko_t *gl)
{
    int player_line = get_playerline(gl);
    int player_column = get_playercolumn(gl);

    if (gl->map[player_line+1][player_column] == ' '
        || gl->map[player_line+1][player_column] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line+1][player_column] = 'P';
    }
    if (gl->map[player_line+1][player_column] == 'X'
        && gl->map[player_line+2][player_column] == ' ') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line+1][player_column] = 'P';
        gl->map[player_line+2][player_column] = 'X';
    }
    if (gl->map[player_line+1][player_column] == 'X'
        && gl->map[player_line+2][player_column] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line+1][player_column] = 'P';
        gl->map[player_line+2][player_column] = 'X';
    }
}

void move_up(gsoko_t *gl)
{
    int player_line = get_playerline(gl);
    int player_column = get_playercolumn(gl);

    if (gl->map[player_line-1][player_column] == ' '
        || gl->map[player_line-1][player_column] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line-1][player_column] = 'P';
    }
    if (gl->map[player_line-1][player_column] == 'X'
        && gl->map[player_line-2][player_column] == ' ') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line-1][player_column] = 'P';
        gl->map[player_line-2][player_column] = 'X';
    }
    if (gl->map[player_line-1][player_column] == 'X'
        && gl->map[player_line-2][player_column] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line-1][player_column] = 'P';
        gl->map[player_line-2][player_column] = 'X';
    }
}

void move_left(gsoko_t *gl)
{
    int player_line = get_playerline(gl);
    int player_column = get_playercolumn(gl);

    if (gl->map[player_line][player_column-1] == ' '
        || gl->map[player_line][player_column-1] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column-1] = 'P';
    }
    if (gl->map[player_line][player_column-1] == 'X'
        && gl->map[player_line][player_column-2] == ' ') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column-1] = 'P';
        gl->map[player_line][player_column-2] = 'X';
    }
    if (gl->map[player_line][player_column-1] == 'X'
        && gl->map[player_line][player_column-2] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column-1] = 'P';
        gl->map[player_line][player_column-2] = 'X';
    }
}

void move_right(gsoko_t *gl)
{
    int player_line = get_playerline(gl);
    int player_column = get_playercolumn(gl);

    if (gl->map[player_line][player_column+1] == ' '
        || gl->map[player_line][player_column+1] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column+1] = 'P';
    }
    if (gl->map[player_line][player_column+1] == 'X'
        && gl->map[player_line][player_column+2] == ' ') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column+1] = 'P';
        gl->map[player_line][player_column+2] = 'X';
    }
    if (gl->map[player_line][player_column+1] == 'X'
        && gl->map[player_line][player_column+2] == 'O') {
        gl->map[player_line][player_column] = ' ';
        gl->map[player_line][player_column+1] = 'P';
        gl->map[player_line][player_column+2] = 'X';
    }
}
