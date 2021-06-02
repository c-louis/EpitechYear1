/*
** EPITECH PROJECT, 2020
** ia
** File description:
** ia for the matchstick
*/

#include <stdlib.h>

#include "my.h"

int special_case_early(int *map, int mapsize, int take)
{
    int line_dif_one = 0;
    int line_one = 0;
    int line_value = 0;
    for (int i = 0; i < mapsize; i++) {
        if (map[i] != 0 && map[i] != 1) {
            line_dif_one++;
            line_value = map[i];
        } else if (map[i] == 1)
            line_one++;
    }
    if (line_dif_one == 1 && line_value <= take && line_one % 2 == 1) {
        for (int i = 0; i < mapsize; i++)
            map[i] = (map[i] == line_value) ? 0 : map[i];
        return (1);
    } else if (line_dif_one == 1 && line_value <= take && line_one % 2 == 0) {
        for (int i = 0; i < mapsize; i++)
            map[i] = (map[i] == line_value) ? 1 : map[i];
        return (1);
    } return (0);
}

int *get_endline(int *map, int mapsize)
{
    int *end_line = malloc(sizeof(int) * 2);
    int line_a = 100;
    int line_b = 100;

    for (int i = 0; i < mapsize; i++) {
        if (line_a == 100 && map[i] != 0) {
            line_a = i;
            continue;
        }
        if (line_a != 100 && i != line_a && map[i] != 0)
            line_b = i;
    }
    end_line[0] = line_a;
    end_line[1] = line_b;
    return (end_line);
}

int two_line_lastcase(int *map, int take, int line_a, int line_b)
{
    if (map[line_a] == 1 && map[line_b] <= take) {
        map[line_b] = 0;
        return (0);
    }
    if (map[line_b] == 1 && map[line_a] <= take) {
        map[line_a] = 0;
        return (0);
    }
    if (map[line_a] == 1 && map[line_b] > take) {
        map[line_b] = map[line_b] - 1;
        return (0);
    }
    if (map[line_b] == 1 && map[line_a] > take) {
        map[line_a] = map[line_a] - 1;
        return (0);
    }
    return (1);
}

int two_line_ia(int *map, int mapsize, int take)
{
    int *end_line = get_endline(map, mapsize);
    int line_a = end_line[0];
    int line_b = end_line[1];

    if (map[line_a] > 1 && map[line_b] > 1) {
        if (map[line_a] <= take)
            map[line_a] = 1;
        if (map[line_b] <= take && map[line_a] != 1)
            map[line_b] = 1;
        if (map[line_a] != 1 && map[line_b] != 1)
            map[line_a] = map[line_a] - 1;
        return (0);
    }
    if (two_line_lastcase(map, take, line_a, line_b) == 0)
        return (0);
    free(end_line);
    return (1);
}

