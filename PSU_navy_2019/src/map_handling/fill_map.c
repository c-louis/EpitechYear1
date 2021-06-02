/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** fill_map
*/

#include "my.h"
#include "navy.h"

int put_boat_line(char *data_line, int **map)
{
    int len_x = data_line[5] - data_line[2];
    int len_y = data_line[6] - data_line[3];
    int boat_number = my_getnbr(data_line);
    int x = data_line[2] - 49;
    int y = data_line[3] - 49;

    for (int i = 0; i < boat_number; i++) {
        if (map[y][x] == '.')
            map[y][x] = boat_number + 48;
        else {
            return (84);
        }
        x += (len_x != 0) ? 1 : 0;
        len_x -= (len_x != 0) ? 1 : 0;
        y += (len_y != 0) ? 1 : 0;
        len_y -= (len_y != 0) ? 1 : 0;
    }
    return (0);
}

int put_boat_on_map(char **data_map, int **map)
{
    for (int i = 0; data_map[i]; i++) {
        if (put_boat_line(data_map[i], map) == 84) {
            return (84);
        }
    }
    return (0);
}
