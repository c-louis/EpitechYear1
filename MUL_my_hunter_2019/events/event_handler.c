/*
** EPITECH PROJECT, 2019
** event_handler
** File description:
** handler some event
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void dispatch_focus_event(sfRenderWindow *window, sfEvent *event, glg_t *gl)
{
    switch (event->type) {
    case sfEvtClosed:
        close_window(window);
        break;
    case sfEvtLostFocus:
        gl->game->state = 2;
        sfRenderWindow_setFramerateLimit(window, 1);
        break;
    case sfEvtGainedFocus:
        sfRenderWindow_setFramerateLimit(window, 60);
        break;
    default:
        break;
    }
}

void key_pressed(sfEvent *event, glg_t *gl)
{
    if (event->key.code == sfKeyEscape && gl->game->state == 1) {
        gl->game->state = 2;
    }
    else if (event->key.code == sfKeyEscape && gl->game->state == 2) {
        gl->game->state = 1;
    }
}

void check_rect_contain(sfMouseMoveEvent mouse, glg_t *gl)
{
    sfFloatRect s_b = sfRectangleShape_getGlobalBounds(gl->menu->start_button);
    sfFloatRect c_b = sfRectangleShape_getGlobalBounds(gl->menu->credit_button);
    sfFloatRect e_b = sfRectangleShape_getGlobalBounds(gl->menu->exit_button);
    sfFloatRect t_b = sfRectangleShape_getGlobalBounds(gl->menu->expli_button);
    if (sfFloatRect_contains(&s_b, mouse.x, mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(gl->menu->start_button, sfBlue);
    else
        sfRectangleShape_setFillColor(gl->menu->start_button, sfBlack);
    if (sfFloatRect_contains(&c_b, mouse.x, mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(gl->menu->credit_button, sfBlue);
    else
        sfRectangleShape_setFillColor(gl->menu->credit_button, sfBlack);
    if (sfFloatRect_contains(&e_b, mouse.x, mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(gl->menu->exit_button, sfBlue);
    else
        sfRectangleShape_setFillColor(gl->menu->exit_button, sfBlack);
    if (sfFloatRect_contains(&t_b, mouse.x, mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(gl->menu->expli_button, sfBlue);
    else
        sfRectangleShape_setFillColor(gl->menu->expli_button, sfBlack);
}

void set_pointer_pos(sfMouseMoveEvent mouse, glg_t *gl)
{
    sfVector2f pos = {mouse.x - 25, mouse.y - 25};
    sfVector2f pos2 = {mouse.x, mouse.y};
    sfSprite_setPosition(gl->menu->pointer->sprite, pos2);
    sfSprite_setPosition(gl->pointer->sprite, pos);
    check_rect_contain(mouse, gl);
}
