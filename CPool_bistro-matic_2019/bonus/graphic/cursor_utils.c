/*
** EPITECH PROJECT, 2019
** cursor_utils
** File description:
** utils function for the cursor
*/


#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"

void translate_text(globals_t *gl)
{
    sfVector2f t_pos = sfText_getPosition(gl->in);
    float curr = sfText_findCharacterPos(gl->in, gl->cursor_pos).x;
    float t_width = sfText_getLocalBounds(gl->in).width;

    if (curr > 4 && curr < gl->mode.width - 8)
        return;
    if (curr >= gl->mode.width - 8)
        t_pos.x += gl->mode.width - curr - 7;
    else
        t_pos.x -= curr - 7;
    sfText_setPosition(gl->in, t_pos);
}

void key_pressed(sfKeyCode key, globals_t *gl)
{
    char const *current = sfText_getString(gl->in);
    int len = my_strlen(current);

    remove_cursor(gl->cursor_pos, gl);
    if (key == sfKeyLeft && gl->cursor_pos > 0)
        gl->cursor_pos = gl->cursor_pos - 1;
    else if (key == sfKeyRight && gl->cursor_pos < len)
        gl->cursor_pos = gl->cursor_pos + 1;
    translate_text(gl);
    draw_cursor(gl->cursor_pos, gl);
    gl->blink_count = 0;
    gl->is_updating = 1;
}

void blinker(globals_t *gl)
{
    gl->blink_count = gl->blink_count + 1;
    if (gl->blink_count == 1){
        draw_cursor(gl->cursor_pos, gl);
        gl->is_updating = 1;
    }else if (gl->blink_count == 60){
        remove_cursor(gl->cursor_pos, gl);
        gl->is_updating = 1;
    }
    if (gl->blink_count > 80)
        gl->blink_count = 0;
}

void remove_cursor(int pos, globals_t *gl)
{
    sfVector2f p = sfText_findCharacterPos(gl->in, pos);
    sfIntRect cur = {p.x, p.y + 2, 1, 20};

    draw_rect(gl->fb, cur, sfWhite);
    gl->pix = create_sprite_from_framebuffer(gl, &(gl->mode));
}

void draw_cursor(int pos, globals_t *gl)
{
    sfVector2f p = sfText_findCharacterPos(gl->in, pos);
    sfIntRect cur = {p.x, p.y + 2, 1, 20};

    draw_rect(gl->fb, cur, sfBlack);
    gl->pix = create_sprite_from_framebuffer(gl, &(gl->mode));
}

