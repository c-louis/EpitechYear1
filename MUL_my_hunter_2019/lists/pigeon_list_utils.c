/*
** EPITECH PROJECT, 2019
** pigeon_list_utils
** File description:
** utility function to manipulate the pigeon list
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void make_new_pigeon(pigeon_t *new_pig, glg_t *gl)
{
    sfIntRect rect = {2, 2, 165, 155};
    sfIntRect hitbox = {0, 0, 150, 58};
    sfVector2f pos = {-500, 200};
    new_pig->sprite = sfSprite_create();
    sfSprite_setTexture(new_pig->sprite, gl->pigeon_texture, 0);
    sfSprite_setTextureRect(new_pig->sprite, rect);
    sfSprite_setPosition(new_pig->sprite, pos);
    new_pig->rect = rect;
    new_pig->speed = (my_rand()%10)+10;
    new_pig->movement = ((my_rand()%2) == 0) ? 1 : -1;
    new_pig->hitbox = hitbox;
}

void add_pigeon(glg_t *gl)
{
    int i = 0;
    while (gl->pig_list[i] != 0)
        i++;
    pigeon_t **new_plist = malloc(sizeof(pigeon_t)*(i+2));
    for (int y = 0; y < i; y++)
        new_plist[y] = gl->pig_list[y];
    pigeon_t *new_pig = malloc(sizeof(pigeon_t));
    make_new_pigeon(new_pig, gl);
    new_plist[i] = new_pig;
    new_plist[i+1] = 0;
    free(gl->pig_list);
    gl->pig_list = new_plist;
}

void remove_pigeon(glg_t *gl, int delete)
{
    int i = 0;
    int deleted = 0;
    while (gl->pig_list[i] != 0)
        i++;
    pigeon_t **new_plist = malloc(sizeof(pigeon_t)*(i+1));
    for (int y = 0; y-deleted < i; y++) {
        if (y != delete)
            new_plist[y-deleted] = gl->pig_list[y];
        else {
            deleted = 1;
        }
    }
    new_plist[i] = 0;
    sfSprite_destroy(gl->pig_list[delete]->sprite);
    free(gl->pig_list[delete]);
    free(gl->pig_list);
    gl->pig_list = new_plist;
}

void check_pigeon(glg_t *gl)
{
    int i = 0;
    while (gl->pig_list[i] != 0) {
        sfVector2f pos = sfSprite_getPosition(gl->pig_list[i]->sprite);
        if (pos.x > 1765) {
            remove_pigeon(gl, i);
            update_score(gl, -1);
            gl->game->pigeon_missed = gl->game->pigeon_missed + 1;
            return;
        }
        i++;
    }
}
