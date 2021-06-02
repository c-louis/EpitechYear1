/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding utils functions
*/

#include <stdlib.h>

#include "lemin.h"

path_t *continue_path(path_t *path, room_t *new_room)
{
    path_t *new_path = malloc(sizeof(path_t));
    path_t *end = path;
    int cur_size = 0;

    if (!new_path)
        return (0);
    new_path->next = 0;
    for (; path->path[cur_size] != 0; cur_size++);
    if (!(new_path->path = malloc(sizeof(room_t *) * (cur_size + 2))))
        return (0);
    for (int i = 0; i < cur_size; i++)
        new_path->path[i] = path->path[i];
    new_path->path[cur_size] = new_room;
    new_path->path[cur_size + 1] = 0;
    new_room->visited = 1;
    while (end->next)
        end = end->next;
    end->next = new_path;
    new_path->prev = end;
    return (new_path);
}

path_t *append_path(path_t *path)
{
    int rooms = 0;
    room_t *cur = 0;

    for (; path->path[rooms] != 0; rooms++);
    cur = path->path[rooms - 1];
    for (int i = 0; cur->next[i] != 0; i++){
        if (cur->next[i]->type == END)
            return (continue_path(path, cur->next[i]));
        if (cur->next[i]->busy || cur->next[i]->visited)
            continue;
        continue_path(path, cur->next[i]);
    }
    return (0);
}

void remove_node(path_t *node, path_t **queue)
{
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    if (*queue == node)
        *queue = node->next;
    free(node->path);
    free(node);
}
