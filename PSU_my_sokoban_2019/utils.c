/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utility function
*/

#include <stdio.h>
#include "sokoban.h"
#include "my.h"

int get_playerline(gsoko_t *gl)
{
    for (int i = 0; gl->map[i] != 0; i++) {
        for (int y = 0; gl->map[i][y] != 0; y++) {
            if (gl->map[i][y] == 'P')
                return (i);
        }
    }
}

int get_playercolumn(gsoko_t *gl)
{
    for (int i = 0; gl->map[i] != 0; i++) {
        for (int y = 0; gl->map[i][y] != 0; y++) {
            if (gl->map[i][y] == 'P')
                return (y);
        }
    }
}

int check_basic_error(int ac, char **av)
{
    FILE *fd = fopen(av[1], "r");
    if (fd == NULL) {
        return (84);
    } else {
        fclose(fd);
    }
    return (0);
}

void print_help(void)
{
    my_printf("USAGE\n\t./my_sokoban map\n");
    my_printf("DESCRIPTION\n\tmap\tfile representing the warehouse map,");
    my_printf(" containing '#' for walls,\n\t\t'P' for the players, 'X' ");
    my_printf("for boxes and 'O' for storage location\n");
}
