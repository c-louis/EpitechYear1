/*
** EPITECH PROJECT, 2019
** click_handler
** File description:
** dispatch the click event to the right function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void game_click_handler(sfEvent *event, glg_t *gl)
{
    sfMouseButtonEvent data = event->mouseButton;

    if (gl->ammo <= 0)
        return;
    gl->ammo = gl->ammo - 1;
    if (gl->ammo == 0)
        gl->ammo = -45;
    handle_shoot_sound(gl);
    handle_shoot_bullet(gl, data);
    check_hit_pos(data, gl);
}

void menu_click_handler(sfEvent *event, glg_t *gl)
{
    sfMouseButtonEvent mouse = event->mouseButton;
    sfVector2f pos = {event->mouseButton.x, event->mouseButton.y};
    sfFloatRect s_b = sfRectangleShape_getGlobalBounds(gl->menu->start_button);
    sfFloatRect c_b = sfRectangleShape_getGlobalBounds(gl->menu->credit_button);
    sfFloatRect e_b = sfRectangleShape_getGlobalBounds(gl->menu->exit_button);
    sfFloatRect t_b = sfRectangleShape_getGlobalBounds(gl->menu->expli_button);

    sfSprite_setPosition(gl->menu->pointer->sprite, pos);
    if (sfFloatRect_contains(&s_b, mouse.x, mouse.y) == sfTrue)
        gl->game->state = 1;
    if (sfFloatRect_contains(&t_b, mouse.x, mouse.y) == sfTrue)
        gl->game->state = 3;
    if (sfFloatRect_contains(&c_b, mouse.x, mouse.y) == sfTrue)
        gl->game->state = 4;
    if (sfFloatRect_contains(&e_b, mouse.x, mouse.y) == sfTrue)
        close_window(gl->window);
}

void expli_click_handler(sfEvent *event, glg_t *gl)
{
    sfMouseButtonEvent mouse = event->mouseButton;
    sfFloatRect s_b = sfSprite_getGlobalBounds(gl->expli->echap_img->sprite);

    if (sfFloatRect_contains(&s_b, mouse.x, mouse.y) == sfTrue) {
        gl->game->state = 0;
    }
}

void click_handler(sfEvent *event, glg_t *gl)
{
    if (gl->game->state == 1)
        game_click_handler(event, gl);
    if (gl->game->state == 0 || gl->game->state == 2)
        menu_click_handler(event, gl);
    if (gl->game->state == 3 || gl->game->state == 4)
        expli_click_handler(event, gl);
}
