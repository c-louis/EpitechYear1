/*
** EPITECH PROJECT, 2020
** match_ia_second
** File description:
** heyyyya
*/

#include <stdlib.h>

#include "my.h"
#include "matchstick.h"

int early_game_ia(int *map, int mapsize, int take)
{
    int line = 0;
    int to_take = take;

    if (special_case_early(map, mapsize, take) == 1)
        return (0);
    for (int i = 0; i < mapsize; i++) {
        if (map[line] < map[i])
            line = i;
    }
    while (map[line] - to_take <= 0)
        to_take--;
    if (to_take == 0)
        to_take++;
    map[line] = map[line] - to_take;
    return (0);
}

int one_line_ia(int *map, int mapsize, int take)
{
    int to_take = take;

    for (int i = 0; i < mapsize; i++) {
        if (map[i] > 0 && map[i] > 1) {
            if (map[i] - take <= 0) {
                map[i] = 1;
                return (0);
            } else {
                map[i] = map[i] - 1;
            }
        }
        else if (map[i] > 0 && map[i] == 1) {
            map[i] = 0;
            return (0);
        }
    }
}

int print_modification(int *map, int *save, int mapsize)
{
    for (int i = 0; i < mapsize; i++) {
        if (map[i] != save[i]) {
            my_printf("AI removed %d match(es) from line %d\n",
                save[i]-map[i], i+1);
            free(save);
            return (0);
        }
    }
    free(save);
    return (1);
}

int input_ia(int *map, int mapsize, int take)
{
    int line = 0;
    int line_count = 0;
    int *save = malloc(sizeof(int) * mapsize);

    for (int i = 0; i < mapsize; i++)
        if (map[i] != 0)
            line_count++;
    for (int i = 0; i < mapsize; i++)
        save[i] = map[i];
    if (line_count > 2)
        early_game_ia(map, mapsize, take);
    if (line_count == 1)
        one_line_ia(map, mapsize, take);
    if (line_count == 2)
        two_line_ia(map, mapsize, take);
    return (print_modification(map, save, mapsize));
}
