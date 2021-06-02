/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** launch_navy
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>

#include "navy.h"
#include "my.h"

extern global_t *NAVY;

void print_maps(void)
{
    my_printf("my positions:\n");
    print_map(NAVY->myMap);
    my_printf("\nenemy's positions:\n");
    print_map(NAVY->enemyMap);
    my_printf("\n");
}

int p1_launch(char *map_file)
{
    int global_sig = init_global(map_file, NULL);

    if (global_sig != 0)
        return (global_sig);
    NAVY->turn = 1;
    while (game_loop());
    return (0);
}

int p2_launch(char *pid_player, char *map_file)
{
    int global_sig = init_global(map_file, pid_player);

    if (global_sig != 0)
        return (global_sig);
    NAVY->turn = 0;
    while (game_loop());
    return (0);
}
