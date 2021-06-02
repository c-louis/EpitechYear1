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

int **get_map(char *map_file)
{
    char **array_map = NULL;
    int **map = NULL;

    array_map = open_file(map_file);
    if (!array_map) {
        my_printf("80\n");
        return (NULL);
    }
    map = convert_map(array_map);
    if (!map) {
        my_printf("79\n");
        return (NULL);
    }
    free_my_str_array(array_map);
    return (map);
}

void prepare_sigaction(void)
{
    struct sigaction action;

    action.sa_sigaction = &receive_signal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
}

int **get_empty_map(void)
{
    int **map = load_blank_map();

    return (map);
}

int init_global(char *map_file, char *pid)
{
    NAVY = malloc(sizeof(global_t));
    if (NAVY == NULL)
        return (81);
    NAVY->coord = malloc(sizeof(coord_t));
    if (NAVY->coord == NULL)
        return (82);
    NAVY->myMap = get_map(map_file);
    NAVY->enemyMap = get_empty_map();
    NAVY->state = 1;
    NAVY->me = getpid();
    NAVY->sig_c = 0;
    if (pid == NULL)
        NAVY->enemy = -1;
    else
        NAVY->enemy = my_getnbr(pid);
    if (NAVY->myMap == NULL)
        return (83);
    prepare_sigaction();
    return (0);
}
