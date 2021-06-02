/*
** EPITECH PROJECT, 2019
** menu_loop.c
** File description:
** menu_loop contain all the loop for the menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void menu_loop(sfRenderWindow *window, glg_t *gl)
{
    sfRenderWindow_drawRectangleShape(window, gl->menu->background, 0);
    sfRenderWindow_drawText(window, gl->menu->title, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->start_button, 0);
    sfRenderWindow_drawText(window, gl->menu->start_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->exit_button, 0);
    sfRenderWindow_drawText(window, gl->menu->exit_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->credit_button, 0);
    sfRenderWindow_drawText(window, gl->menu->credit_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->expli_button, 0);
    sfRenderWindow_drawText(window, gl->menu->expli_txt, 0);
    sfRenderWindow_drawSprite(window, gl->menu->pointer->sprite, 0);
}

void pause_loop(sfRenderWindow *window, glg_t *gl)
{
    for (int i = 0; gl->pig_list[i] != 0; i++)
        sfRenderWindow_drawSprite(window, gl->pig_list[i]->sprite, 0);
    for (int i = 0; gl->dead_pigeon[i] != 0; i++)
        sfRenderWindow_drawSprite(window, gl->dead_pigeon[i]->sprite, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->background, 0);
    sfRenderWindow_drawText(window, gl->menu->pause_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->start_button, 0);
    sfRenderWindow_drawText(window, gl->menu->resume_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->exit_button, 0);
    sfRenderWindow_drawText(window, gl->menu->exit_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->credit_button, 0);
    sfRenderWindow_drawText(window, gl->menu->credit_txt, 0);
    sfRenderWindow_drawRectangleShape(window, gl->menu->expli_button, 0);
    sfRenderWindow_drawText(window, gl->menu->expli_txt, 0);
    sfRenderWindow_drawSprite(window, gl->menu->pointer->sprite, 0);
    sfRenderWindow_drawText(window, gl->game->score_txt, 0);
}

void explication_loop(sfRenderWindow *window, glg_t *gl)
{
    sfRenderWindow_drawRectangleShape(window, gl->expli->background, 0);
    sfRenderWindow_drawText(window, gl->expli->title, 0);
    sfRenderWindow_drawSprite(window, gl->expli->echap_img->sprite, 0);
    sfRenderWindow_drawSprite(window, gl->expli->mouse_img->sprite, 0);
    sfRenderWindow_drawSprite(window, gl->expli->close_img->sprite, 0);
    sfRenderWindow_drawText(window, gl->expli->echap_txt, 0);
    sfRenderWindow_drawText(window, gl->expli->mouse_txt, 0);
    sfRenderWindow_drawSprite(window, gl->menu->pointer->sprite, 0);
}

void credit_loop(sfRenderWindow *window, glg_t *gl)
{
    sfRenderWindow_drawRectangleShape(window, gl->expli->background, 0);
    sfRenderWindow_drawSprite(window, gl->expli->echap_img->sprite, 0);
    sfRenderWindow_drawSprite(window, gl->menu->pointer->sprite, 0);
    sfRenderWindow_drawText(window, gl->credit->title, 0);
    sfRenderWindow_drawText(window, gl->credit->fond, 0);
    sfRenderWindow_drawText(window, gl->credit->pigeon, 0);
    sfRenderWindow_drawText(window, gl->credit->shoot, 0);
    sfRenderWindow_drawText(window, gl->credit->death, 0);
    sfRenderWindow_drawText(window, gl->credit->impact, 0);
}
