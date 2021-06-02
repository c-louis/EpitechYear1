/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include <stdlib.h>

#include "lemin.h"

path_t *create_queue(int pos, room_t **anthill)
{
    path_t *queue = malloc(sizeof(path_t));

    if (!queue)
        return (0);
    queue->next = 0;
    queue->prev = 0;
    queue->path = malloc(sizeof(room_t *) * 2);
    if (!queue->path)
        return (0);
    queue->path[0] = anthill[pos];
    queue->path[1] = 0;
    anthill[pos]->visited = 1;
    return (queue);
}

void free_queue(path_t *queue)
{
    path_t *next = 0;

    while (queue != 0){
        next = queue->next;
        free(queue->path);
        free(queue);
        queue = next;
    }
}

path_t *find_end(path_t **queue)
{
    path_t *solution = 0;
    path_t *next = 0;
    path_t *current = *queue;

    if (!current)
        return ((path_t *) 1);
    while (current != 0){
        next = current->next;
        if (solution = append_path(current))
            break;
        remove_node(current, queue);
        current = next;
    }
    return (solution);
}

int get_next_move(int pos, room_t **anthill)
{
    path_t *queue = create_queue(pos, anthill);
    path_t *shortest;
    int next_move = -1;

    if (!queue){
        for (int i = 0; anthill[i] != 0; i++)
            anthill[i]->visited = 0;
        return (-1);
    }
    while (!(shortest = find_end(&queue)));
    if (shortest != (path_t *) 1)
        next_move = shortest->path[1]->id;
    for (int i = 0; anthill[i] != 0; i++)
        anthill[i]->visited = 0;
    if (next_move >= 0){
        anthill[pos]->busy = 0;
        anthill[next_move]->busy = 1;
    }
    free_queue(queue);
    return (next_move);
}
