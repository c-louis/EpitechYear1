/*
** EPITECH PROJECT, 2019
** dead_pigeon_list_utils.c
** File description:
** dead pigeon utility function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void copy_pigeon(pigeon_t *copy, pigeon_t *to_copy)
{
    copy->sprite = sfSprite_create();
    copy->sprite = sfSprite_copy(to_copy->sprite);
    copy->rect = to_copy->rect;
    copy->hitbox = to_copy->hitbox;
    copy->speed = 0;
    copy->movement = 0;
}

void add_dead_pigeon(glg_t *gl, pigeon_t *to_add)
{
    int i = 0;
    while (gl->dead_pigeon[i] != 0)
        i++;
    pigeon_t **new_plist = malloc(sizeof(pigeon_t)*(i+2));
    for (int y = 0; y < i; y++)
        new_plist[y] = gl->dead_pigeon[y];
    pigeon_t *copy = malloc(sizeof(pigeon_t));
    copy_pigeon(copy, to_add);
    new_plist[i] = copy;
    new_plist[i+1] = 0;
    free(gl->dead_pigeon);
    gl->dead_pigeon = new_plist;
}

void remove_dead_pigeon(glg_t *gl, int delete)
{
    int i = 0;
    int deleted = 0;
    while (gl->dead_pigeon[i] != 0)
        i++;
    pigeon_t **new_plist = malloc(sizeof(pigeon_t)*(i+1));
    for (int y = 0; y-deleted < i; y++) {
        if (y != delete)
            new_plist[y-deleted] = gl->dead_pigeon[y];
        else {
            deleted = 1;
        }
    }
    new_plist[i] = 0;
    sfSprite_destroy(gl->dead_pigeon[delete]->sprite);
    free(gl->dead_pigeon[delete]);
    free(gl->dead_pigeon);
    gl->dead_pigeon = new_plist;
}