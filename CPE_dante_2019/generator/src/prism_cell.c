/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** prism_cell
*/

#include <stdlib.h>
#include <stddef.h>
#include "dante.h"
#include "my.h"

chain_t *get_random_wall(list_t *wall)
{
    int random = rand()%(wall->length > 10 ? 10 : wall->length);
    chain_t *random_wall = wall->head;
    int len = 0;

    for (int i = 0; random_wall && i != random; i++) {
        random_wall = random_wall->next;
    }
    if (random_wall == NULL)
        printf("NULL\n");
    return (random_wall);
}

int add_wall_to_list(list_t *wall, int x, int y)
{
    static long int id = 0;
    chain_t *tmp = malloc(sizeof(chain_t));
    chain_t *iteration = wall->head;

    if (tmp == NULL)
        return (84);
    tmp->x_cell = x;
    tmp->y_cell = y;
    tmp->id = id;
    tmp->next = NULL;
    id++;
    wall->length = wall->length + 1;
    tmp->next = wall->head;
    tmp->prev = NULL;
    if (iteration != NULL)
        iteration->prev = tmp;
    wall->head = tmp;
    return (0);
}

int remove_wall(list_t *wall, int id, chain_t *delete)
{
    chain_t *iteration = wall->head;
    chain_t *tmp = NULL;

    if (iteration != NULL && iteration->id == id){
        wall->head = iteration->next;
        free(iteration);
        wall->length = wall->length - 1;
        return (1);
    }
    while (iteration != NULL && iteration->id != id) {
        tmp = iteration;
        iteration = iteration->next;
    }
    if (iteration == NULL) return (0);
    tmp->next = iteration->next;
    free(iteration);
    wall->length = wall->length - 1;
    return (1);
}