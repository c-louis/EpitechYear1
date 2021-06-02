/*
** EPITECH PROJECT, 2019
** alive_pigeon_anim
** File description:
** animation function for the aliv pigeon
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void animate_pigeon(glg_t *gl)
{
    int i = 0;
    while (gl->pig_list[i] != NULL) {
        pigeon_t *pigeon = gl->pig_list[i];
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
        i++;
    }
}

int move_y(pigeon_t *pigeon)
{
    if (pigeon->movement >= 1) {
        if (pigeon->movement < 10) {
            pigeon->movement = pigeon->movement + 1;
        }
        if (pigeon->movement == 10)
            pigeon->movement = ((my_rand()%2) == 0) ? 1 : -1;
        return (5);
    }
    if (pigeon->movement <= -1) {
        if (pigeon->movement > -10) {
            pigeon->movement = pigeon->movement - 1;
        }
        if (pigeon->movement == -10)
            pigeon->movement = ((my_rand()%2) == 0) ? 1 : -1;
        return (-5);
    }
    return (0);
}

void move_pigeon(glg_t *gl)
{
    int i = 0;
    while (gl->pig_list[i] != 0) {
        pigeon_t *pigeon = gl->pig_list[i];
        sfIntRect hitbox = pigeon->hitbox;
        sfVector2f vect = sfSprite_getPosition(pigeon->sprite);
        vect.x = vect.x + pigeon->speed;
        vect.y = vect.y + move_y(pigeon);
        hitbox.left = vect.x;
        hitbox.top = vect.y+20;
        pigeon->hitbox = hitbox;
        sfSprite_setPosition(pigeon->sprite, vect);
        i++;
    }
}
