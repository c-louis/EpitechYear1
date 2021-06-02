/*
** EPITECH PROJECT, 2019
** topbar
** File description:
** function to handle a topbar
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"

void clear(sfEvent *event, globals_t *gl)
{
    sfFloatRect rect = sfText_getGlobalBounds(gl->bartext->basic);
    if (sfFloatRect_contains(&rect,
    event->mouseButton.x, event->mouseButton.y)) {
        gl->result = malloc(sizeof(sfText *));
        gl->result[0] = 0;
        gl->is_updating = 1;
    }
}

void draw_topbar_text(globals_t *gl, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, gl->bartext->basic, 0);
}

void init_topbar(globals_t *gl)
{
    sfVector2f p_bas = {3, 2};
    sfVector2f p_but = {100, 2};
    gl->bartext = malloc(sizeof(topbar_t));
    gl->bartext->basic = sfText_create();
    sfText_setPosition((gl->bartext->basic), p_bas);
    sfText_setColor((gl->bartext->basic), sfWhite);
    sfText_setFont((gl->bartext->basic), gl->font);
    sfText_setCharacterSize((gl->bartext->basic), 14);
    sfText_setString((gl->bartext->basic), "Clear");
}

void draw_topbar_box(framebuffer_t *fb)
{
    sfIntRect rect = {0, 0, 400, 20};
    sfColor c = {125, 125, 125, 255};
    sfIntRect inside = {rect.left +1, rect.top + 1,
    rect.width - 2 * 1, rect.height - 1};
    draw_rect(fb, rect, c);
    draw_rect(fb, inside, sfBlack);
}
