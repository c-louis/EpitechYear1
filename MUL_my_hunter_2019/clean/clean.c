/*
** EPITECH PROJECT, 2019
** clean the memory
** File description:
** clean all the memory
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "graph.h"

void clean_font(glg_t *gl)
{
    sfFont_destroy(gl->arial);
    sfFont_destroy(gl->bitwonder);
}

void clean_texture_image(glg_t *gl)
{
    sfTexture_destroy(gl->pigeon_texture);
    sfTexture_destroy(gl->bullet_texture);
    sfTexture_destroy(gl->fond->texture);
    sfTexture_destroy(gl->pointer->texture);
    sfTexture_destroy(gl->ammo_i->texture);
    sfSprite_destroy(gl->fond->sprite);
    sfSprite_destroy(gl->pointer->sprite);
    sfSprite_destroy(gl->ammo_i->sprite);
    free(gl->fond);
    free(gl->pointer);
    free(gl->ammo_i);
}

void clean_menu(glg_t *gl)
{
    sfRectangleShape_destroy(gl->menu->background);
    sfRectangleShape_destroy(gl->menu->start_button);
    sfText_destroy(gl->menu->title);
    sfText_destroy(gl->menu->start_txt);
    sfTexture_destroy(gl->menu->pointer->texture);
    sfSprite_destroy(gl->menu->pointer->sprite);
    free(gl->menu->pointer);
    free(gl->menu);
}

void clean_game(glg_t *gl)
{
    sfText_destroy(gl->game->score_txt);
    free(gl->game);
}

void clean_all(glg_t *gl)
{
    clean_pigeon_list(gl);
    clean_font(gl);
    clean_texture_image(gl);
    clean_sounds(gl);
    clean_bullet(gl);
    clean_menu(gl);
    clean_game(gl);
    free(gl);
}
