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

void init_explication_txt(glg_t *gl)
{
    sfVector2f mouse_pos = {515, 375};
    sfVector2f echap_pos = {515, 525};

    gl->expli->echap_txt = sfText_create();
    sfText_setFont(gl->expli->echap_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->expli->echap_txt, 23);
    sfText_setString(gl->expli->echap_txt, "Press Escape to pause the game");
    sfText_setPosition(gl->expli->echap_txt, echap_pos);
    sfText_setColor(gl->expli->echap_txt, sfWhite);
    gl->expli->mouse_txt = sfText_create();
    sfText_setFont(gl->expli->mouse_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->expli->mouse_txt, 23);
    sfText_setString(gl->expli->mouse_txt, "Use your mouse to kill the pigeon");
    sfText_setPosition(gl->expli->mouse_txt, mouse_pos);
    sfText_setColor(gl->expli->mouse_txt, sfWhite);
}

void set_explication_img_scale(glg_t *gl)
{
    sfVector2f echap_sc = {0.12, 0.12};
    sfVector2f mouse_sc = {0.17, 0.17};
    sfVector2f close_sc = {0.9, 0.9};

    sfSprite_setScale(gl->expli->echap_img->sprite, echap_sc);
    sfSprite_setScale(gl->expli->mouse_img->sprite, mouse_sc);
    sfSprite_setScale(gl->expli->close_img->sprite, close_sc);
}

void init_explication_img(glg_t *gl)
{
    gl->expli->echap_img = malloc(sizeof(image_t));
    gl->expli->mouse_img = malloc(sizeof(image_t));
    gl->expli->close_img = malloc(sizeof(image_t));
    init_text_sprite_expli(gl);
    set_explication_img_scale(gl);
}

void init_explication_background(glg_t *gl)
{
    sfVector2f size = {800, 500};
    sfVector2f pos = {400, 200};
    sfVector2f pos_tit = {625, 225};

    gl->expli = malloc(sizeof(explication_t));
    gl->expli->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->expli->background, sfBlack);
    sfRectangleShape_setOutlineColor(gl->expli->background, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->expli->background, 5);
    sfRectangleShape_setSize(gl->expli->background, size);
    sfRectangleShape_setPosition(gl->expli->background, pos);
    gl->expli->title = sfText_create();
    sfText_setFont(gl->expli->title, gl->bitwonder);
    sfText_setCharacterSize(gl->expli->title, 35);
    sfText_setString(gl->expli->title, "How To Play");
    sfText_setPosition(gl->expli->title, pos_tit);
    sfText_setColor(gl->expli->title, sfWhite);
}

void init_explication(glg_t *gl)
{
    init_explication_background(gl);
    init_explication_img(gl);
    init_explication_txt(gl);
}
