/*
** EPITECH PROJECT, 2019
** init
** File description:
** init all
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

void init_line_anim(glmul_t *gl)
{
    gl->line_anim = malloc(sizeof(animline_t));
    gl->line_anim->lines = malloc(sizeof(line_t *));
    gl->line_anim->lines[0] = 0;
}

void init_sprite(glmul_t *gl)
{
    gl->texture = sfTexture_create(1600, 1000);
    update_sprite_from_framebuffer(gl);
    gl->sprite = sfSprite_create();
    sfSprite_setTexture(gl->sprite, gl->texture, sfTrue);
}

void init_all(glmul_t *gl)
{
    gl->init = 0;
    gl->framebuffer = framebuffer_create(1600, 1000);
    init_line_anim(gl);
    init_sprite(gl);
}
