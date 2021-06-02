/*
** EPITECH PROJECT, 2019
** ncurses sokoban
** File description:
** sokoban ncurses
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include "my.h"
#include "sokoban.h"

void game_loop(gsoko_t *gl)
{
    int key = 0;
    while ((key = getch()) != 27) {
        erase();
        handle_movement(gl, key);
        handle_defeat(gl);
        handle_solution(gl);
        draw_map(gl);
        refresh();
        if (gl->state == 2)
            break;
        if (gl->state == 1)
            break;
    }
}

int check_map(gsoko_t *gl)
{
    char *map = gl->smap;
    int player_count = 0;
    int solution_count = 0;
    int case_count = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            player_count++;
        if (map[i] == 'O')
            solution_count++;
        if (map[i] == 'X')
            case_count++;
        if (map[i] != 'X' && map[i] != 'P' && map[i] != ' '
            && map[i] != '\n' && map[i] != '#' && map[i] != 'O')
            return (84);
    }
    if (player_count > 1 || (solution_count != case_count))
        return (84);
    return (0);
}

int main_soko(int ac, char **av)
{
    gsoko_t *gl = malloc(sizeof(gsoko_t));

    init_soko(gl, ac, av);
    if (check_map(gl) == 84) {
        return (84);
    }
    initscr();
    set_ncurses_param();
    keypad(stdscr, TRUE);
    draw_map(gl);
    game_loop(gl);
    endwin();
    if (gl->state == 2)
        return (0);
    if (gl->state == 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (check_basic_error(ac, av) == 84) {
        return (84);
    } else {
        return (main_soko(ac, av));
    }
}
