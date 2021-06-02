/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** start_lemin
*/

#include <stdlib.h>

#include "lemin.h"

int start_lemin(void)
{
    lemin_t lemin;
    int ret = 0;

    lemin.anthill = malloc(sizeof(room_t *));
    lemin.anthill[0] = NULL;
    if (get_info(&lemin))
        return (84);
    if (start_error(&lemin))
        return (84);
    if (solve(&lemin) < 0)
        ret = 84;
    for (int i = 0; lemin.anthill[i] != NULL; i++){
        free(lemin.anthill[i]->next);
        free(lemin.anthill[i]->name);
        free(lemin.anthill[i]);
    }
    free(lemin.anthill);
    return (ret);
}
