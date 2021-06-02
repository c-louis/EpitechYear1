/*
** EPITECH PROJECT, 2019
** init_menu
** File description:
** init the menu things
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void init_menu_background(glg_t *gl)
{
    sfVector2f size = {400, 495};
    sfVector2f pos = {600, 250};
    sfVector2f pos_tit = {625, 275};

    gl->menu = malloc(sizeof(menu_t));
    gl->menu->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->menu->background, sfBlack);
    sfRectangleShape_setOutlineColor(gl->menu->background, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->menu->background, 5);
    sfRectangleShape_setSize(gl->menu->background, size);
    sfRectangleShape_setPosition(gl->menu->background, pos);
    gl->menu->title = sfText_create();
    sfText_setFont(gl->menu->title, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->title, 35);
    sfText_setString(gl->menu->title, "Pigeon Hunt");
    sfText_setPosition(gl->menu->title, pos_tit);
    sfText_setColor(gl->menu->title, sfWhite);
}

void init_menu(glg_t *gl)
{
    sfVector2f scale = {0.25, 0.25};

    init_menu_background(gl);
    init_menu_startbutton(gl);
    init_menu_pausebutton(gl);
    init_menu_exitbutton(gl);
    init_menu_creditbutton(gl);
    init_menu_explibutton(gl);
    gl->menu->pointer = malloc(sizeof(image_t));
    gl->menu->pointer->texture =
        sfTexture_createFromFile("assets/img/menu_pointer.png", 0);
    sfTexture_setSmooth(gl->menu->pointer->texture, sfTrue);
    gl->menu->pointer->sprite = sfSprite_create();
    sfSprite_setTexture(gl->menu->pointer->sprite,
        gl->menu->pointer->texture, 0);
    sfSprite_setScale(gl->menu->pointer->sprite, scale);
}
