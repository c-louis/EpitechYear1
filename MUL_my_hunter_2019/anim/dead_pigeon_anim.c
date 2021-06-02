/*
** EPITECH PROJECT, 2019
** dead_pigeon_anim
** File description:
** dead_anim
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void anim_dead(pigeon_t *pigeon)
{
    sfIntRect rect = pigeon->rect;
    rect.left = rect.left + 165+2;
    if (rect.left >= 165*4+2*5) {
        rect.left = 2;
        rect.top = rect.top + 155+2;
    }
    if (rect.top >= 155*4+2*5) {
        rect.top = 2;
        rect.left = 2;
    }
    sfSprite_setTextureRect(pigeon->sprite, rect);
    pigeon->rect = rect;
}

void animate_dead_pigeon(glg_t *gl)
{
    int i = 0;
    while (gl->dead_pigeon[i] != 0) {
        pigeon_t *pigeon = gl->dead_pigeon[i];
        sfVector2f vect = sfSprite_getPosition(pigeon->sprite);
        vect.y = vect.y + 10;
        if (vect.y < 950) {
            sfSprite_setPosition(pigeon->sprite, vect);
            anim_dead(pigeon);
        }
        if (vect.y < 800) {
            sfSprite_rotate(pigeon->sprite, 10);
        }
        i++;
    }
}
