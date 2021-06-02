/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick game
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "my.h"
#include "matchstick.h"

void draw_map(int *map, int mapsize)
{
    for (int i = 0; i < mapsize*2+1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0; i < mapsize; i++) {
        write(1, "*", 1);
        for (int y = 0; y < mapsize-i-1; y++)
            write(1, " ", 1);
        for (int y = 0; y < map[i]; y++)
            write(1, "|", 1);
        for (int y = 0; y < mapsize-i-1 + (i*2+1) - map[i]; y++)
            write(1, " ", 1);
        write(1, "*", 1);
        write(1, "\n", 1);
    }
    for (int i = 0; i < mapsize*2+1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

int input_player(int *map, int mapsize, int take)
{
    char *input = NULL;
    size_t len = 0;
    int line, match, read;

    my_printf("Line: ");
    read = getline(&input, &len, stdin);
    if (read == -1) return (84);
    if (is_match_number(input)) return (1);
    line = my_getnbr(input) - 1;
    if (is_line_valid(line, mapsize)) return (1);
    my_printf("Matches: ");
    read = getline(&input, &len, stdin);
    if (read == -1) return (84);
    if (is_match_number(input)) return (1);
    match = my_getnbr(input);
    if (is_match_valid(match, take, map[line]) == 0) return (1);
    map[line] = map[line] - match;
    my_printf("Player removed %d match(es) from line %d\n", match, line+1);
    return (0);
}

int game_loop(int *map, int mapsize, int take)
{
    int win = 0;

    draw_map(map, mapsize);
    my_printf("\nYour turn:\n");
    while (win = input_player(map, mapsize, take))
        if (win == 84)
            return (84);
    win = (check_win(map, mapsize) == 1) ? 2 : 0;
    if (win != 0)
        return (win);
    draw_map(map, mapsize);
    my_printf("\nAI's turn...\n");
    while (input_ia(map, mapsize, take));
    win = (check_win(map, mapsize) == 1) ? 1 : 0;
    if (win != 0)
        return (win);
    return (0);
}

int launch_matchstick(char **av)
{
    int mapsize = my_getnbr(av[1]);
    int take = my_getnbr(av[2]);
    int *map = make_map(mapsize);
    int win = 0;

    while (win == 0) {
        win = game_loop(map, mapsize, take);
    }
    if (win == 84) {
        free(map);
        return (0);
    }
    draw_map(map, mapsize);
    free(map);
    print_win(win);
    return (win);
}
