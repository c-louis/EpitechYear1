/*
** EPITECH PROJECT, 2019
** init_two
** File description:
** main file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void init_font(glg_t *gl)
{
    gl->arial = sfFont_createFromFile("assets/fonts/arial.ttf");
    gl->bitwonder = sfFont_createFromFile("assets/fonts/8bitwonder.ttf");
}

void init_fond(glg_t *gl)
{
    gl->fond = malloc(sizeof(image_t));
    gl->fond->texture = sfTexture_createFromFile("assets/img/fond.png", 0);
    gl->fond->sprite = sfSprite_create();
    sfSprite_setTexture(gl->fond->sprite, gl->fond->texture, 0);
}

void init_pointer(glg_t *gl)
{
    sfVector2f scale = {0.05, 0.05};
    gl->pointer = malloc(sizeof(image_t));
    gl->pointer->texture =
        sfTexture_createFromFile("assets/img/pointer.png", 0);
    sfTexture_setSmooth(gl->pointer->texture, sfTrue);
    gl->pointer->sprite = sfSprite_create();
    sfSprite_setTexture(gl->pointer->sprite, gl->pointer->texture, 0);
    sfSprite_setScale(gl->pointer->sprite, scale);
}
