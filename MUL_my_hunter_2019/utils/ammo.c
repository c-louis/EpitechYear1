/*
** EPITECH PROJECT, 2019
** ammo
** File description:
** handle ammo
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void render_bullet(sfRenderWindow *window, bullet_t *bullet)
{
    bullet->display_time = bullet->display_time + 1;
    sfColor fade = {255, 255, 255, (51-bullet->display_time)*5};
    if (bullet->display_time > 51)
        fade.a = 0;
    sfSprite_setColor(bullet->impact, fade);
    sfRenderWindow_drawSprite(window, bullet->impact, 0);
}

void reload(glg_t *gl)
{
    if (gl->ammo + 1 == 0)
        gl->ammo = 4;
    if (gl->ammo < 0)
        gl->ammo = gl->ammo +1;
}

void set_ammo_rect(glg_t *gl)
{
    sfIntRect rect = {2, 0, 0, 1400};
    switch (gl->ammo) {
    case 1:
        rect.width = 150;
        break;
    case 2:
        rect.width = 300;
        break;
    case 3:
        rect.width = 450;
        break;
    case 4:
        rect.width = 600;
        break;
    default:
        rect.width = 0;
        break;
    }
    sfSprite_setTextureRect(gl->ammo_i->sprite, rect);
}
