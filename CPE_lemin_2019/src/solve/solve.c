/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** solve lemin
*/

#include <stdlib.h>

#include "lemin.h"
#include "my.h"

int solved(int *ants, int end_id)
{
    for (int i = 0; ants[i] != -1; i++)
        if (ants[i] != end_id)
            return (0);
    return (1);
}

int step(int *ants, room_t **anthill, int end_id)
{
    int next_move;
    int space = 0;
    int check = 0;

    for (int i = 0; ants[i] != -1; i++){
        if (ants[i] == end_id ||
            (next_move = get_next_move(ants[i], anthill)) < 0)
            continue;
        next_move >= 0 ? check = 1 : 0;
        if (space)
            my_printf(" ");
        if (!space)
            space ^= 1;
        my_printf("P%i-%s", i + 1, anthill[next_move]->name);
        ants[i] = next_move;
    }
    if (!check)
        return (-1);
    return (my_printf("\n"));
}

int solve(lemin_t *lemin)
{
    int *ants = malloc(sizeof(int) * (lemin->nb_ant + 1));
    int start_id = 0;
    int end_id = 0;

    if (!ants)
        return (-1);
    my_printf("#moves\n");
    for (; lemin->anthill[start_id]->type != START; start_id++);
    for (; lemin->anthill[end_id]->type != END; end_id++);
    for (int i = 0; i < lemin->nb_ant; i++)
        ants[i] = start_id;
    ants[lemin->nb_ant] = -1;
    while (!solved(ants, end_id)){
        if (step(ants, lemin->anthill, end_id) < 0){
            free(ants);
            return (-1);
        }
    }
    free(ants);
    return (0);
}
