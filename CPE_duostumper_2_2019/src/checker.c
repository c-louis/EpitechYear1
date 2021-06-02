/*
** EPITECH PROJECT, 2020
** game_of_life
** File description:
** checker
*/

#include <string.h>

int is_character(char c)
{
    if (c == '.' || c == 'X' || c == '\n')
        return (1);
    return (0);
}

int is_map_okay(char **map)
{
    int is_valid = 1;
    for (int i = 0; map[i]; i++) {
        if (i == 0)
            continue;
        if (strlen(map[i - 1]) != strlen(map[i]))
            return (0);
        for (int y = 0; map[i][y]; y++) {
            is_valid = is_character(map[i][y]);
        }
        if (!is_valid)
            return (0);
    }
    return (1);
}
