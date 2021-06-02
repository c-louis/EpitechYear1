/*
** EPITECH PROJECT, 2019
** visual_bistro
** File description:
** init function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"

void init_globals(globals_t *gl)
{
    gl->font = sfFont_createFromFile("assets/arial.ttf");
    gl->mode.width = 400;
    gl->mode.height = 400;
    gl->mode.bitsPerPixel = 32;
    gl->old_in = malloc(1);
    gl->scroll_pos = 0;
    gl->cursor_pos = 0;
    gl->blink_count = 0;
    gl->calc_mode = 1;
    init_topbar(gl);
}

void init_window(globals_t *gl)
{
    sfVector2f text_position = {5, gl->mode.height - 32};
    sfIntRect text_area = {1, 1, 400-2, gl->mode.height - 40 - 2};
    sfIntRect text_field = {0, gl->mode.height - 40, 400, 40};
    sfColor border_color = {100, 100, 100, 255};

    gl->fb = framebuffer_create(gl->mode.width, gl->mode.height);
    draw_borders(gl->fb, text_area, 1, border_color);
    draw_borders(gl->fb, text_field, 3, border_color);
    draw_topbar_box(gl->fb);
    gl->pix = create_sprite_from_framebuffer(gl, &(gl->mode));
    gl->in = sfText_create();
    sfText_setPosition(gl->in, text_position);
    sfText_setFont(gl->in, gl->font);
    sfText_setColor(gl->in, sfBlack);
    sfText_setCharacterSize(gl->in, 18);
    draw_cursor(gl->cursor_pos, gl);
    gl->result = malloc(sizeof(sfText *));
    gl->result[0] = 0;
    gl->is_updating = 1;
}
