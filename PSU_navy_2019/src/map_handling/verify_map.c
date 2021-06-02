/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** verify_map
*/

#include "navy.h"
#include "my.h"

int is_letter_coord(char c)
{
    char *letter = "ABCDEFGH";

    for (int i = 0; letter[i]; i++) {
        if (letter[i] == c)
            return (1);
    }
    return (0);
}

int verify_line(char *data_line)
{
    if (my_strlen(data_line) != 7)
        return (84);
    if (data_line[1] != ':' || data_line[4] != ':')
        return (84);
    if (!is_letter_coord(data_line[2]) || !is_letter_coord(data_line[5]))
        return (84);
    if ((data_line[3]) > '8' || data_line[3] < '1' ||
        (data_line[6]) > '8' || data_line[6] < '1')
        return (84);
    return (0);
}

int is_boat(int *boat, char c)
{
    switch (c) {
        case '2' :
            boat[0] += 1;
            break;
        case '3' :
            boat[1] += 1;
            break;
        case '4' :
            boat[2] += 1;
            break;
        case '5' :
            boat[3] += 1;
            break;
        default :
            return (84);
    }
    return (0);
}

int verify_total_boat(char **data_map)
{
    int boat[] = {0, 0, 0, 0};

    for (int i = 0; data_map[i]; i++) {
        if (is_boat(boat, data_map[i][0]) == 84)
            return (84);
    }
    for (int i = 0; i < 4; i++) {
        if (boat[i] != 1)
            return (84);
    }
        return (0);
    return (84);
}

int verify_map(char **data_map)
{
    for (int i = 0; data_map[i]; i++) {
        if (verify_line(data_map[i]) == 84 ||
            verify_diag_boat(data_map[i]) == 84) 
            return (84);
    }
    if (verify_total_boat(data_map) == 84)
        return (84);
    return (0);
}