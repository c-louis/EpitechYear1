/*
** EPITECH PROJECT, 2019
** explication init
** File description:
** init all the explication stuct and sfml thing
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void init_sprite_pos(glg_t *gl)
{
    sfVector2f echap_pos = {410, 210};
    sfVector2f mouse_pos = {415, 350};
    sfVector2f close_pos = {415, 500};

    sfSprite_setPosition(gl->expli->echap_img->sprite, echap_pos);
    sfSprite_setPosition(gl->expli->mouse_img->sprite, mouse_pos);
    sfSprite_setPosition(gl->expli->close_img->sprite, close_pos);
}

void init_text_sprite_expli(glg_t *gl)
{
    gl->expli->echap_img->texture =
        sfTexture_createFromFile("assets/img/goback.png", 0);
    gl->expli->mouse_img->texture =
        sfTexture_createFromFile("assets/img/mouse.png", 0);
    gl->expli->close_img->texture =
        sfTexture_createFromFile("assets/img/echap.png", 0);
    gl->expli->echap_img->sprite = sfSprite_create();
    gl->expli->mouse_img->sprite = sfSprite_create();
    gl->expli->close_img->sprite = sfSprite_create();
    sfSprite_setTexture(gl->expli->echap_img->sprite,
        gl->expli->echap_img->texture, 0);
    sfSprite_setTexture(gl->expli->mouse_img->sprite,
        gl->expli->mouse_img->texture, 0);
    sfSprite_setTexture(gl->expli->close_img->sprite,
        gl->expli->close_img->texture, 0);
    init_sprite_pos(gl);
}
