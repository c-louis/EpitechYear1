/*
** EPITECH PROJECT, 2019
** visual-bistro
** File description:
** Scroll handler
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"

void draw_scrollbar(globals_t *gl)
{
    int len = my_len(gl->result);
    sfVector2f lowest = sfText_getPosition(gl->result[0]);
    sfVector2f highest = sfText_getPosition(gl->result[len - 1]);
    float dist = highest.y - lowest.y;
    float ratio = (gl->mode.height - 40) / dist;
    int size = ratio * (gl->mode.height - 40 - 8 - 20);
    float pos = 1 + gl->scroll_pos / (lowest.y - gl->scroll_pos);
    sfIntRect right = {gl->mode.width - 5, 23, 2, gl->mode.height - 60 - 6};
    sfIntRect bar = {gl->mode.width - 5, pos * (gl->mode.height - 40 - size
        - 6 - 20) + 23, 2, size};

    if (dist < gl->mode.width - 40)
        return;
    draw_rect(gl->fb, right, sfWhite);
    draw_rect(gl->fb, bar, sfBlack);
    gl->pix = create_sprite_from_framebuffer(gl, &(gl->mode));
}

void scroll(float delta, globals_t *gl)
{
    sfVector2f to_update;
    int len = my_len(gl->result);
    if (len > 0) {
        sfVector2f lowest = sfText_getPosition(gl->result[0]);
        sfVector2f highest = sfText_getPosition(gl->result[len - 1]);
        float size = sfText_getLocalBounds(gl->result[len - 1]).height * 2;

        if (len < 10 || lowest.y + delta * 5 - 3 > 20
            || highest.y + delta * 5 + size < gl->mode.height - 40)
            return;
        for (int i = 0; gl->result[i] != 0; i++){
            to_update = sfText_getPosition(gl->result[i]);
            to_update.y += delta * 5;
            sfText_setPosition(gl->result[i], to_update);
        }
        gl->scroll_pos += delta * 5;
        draw_scrollbar(gl);
        gl->is_updating = 1;
    }
}

void scroll_to_bottom(globals_t *gl)
{
    int len = my_len(gl->result);
    int offset;
    sfVector2f to_update;

    if (len < 1)
        return;
    offset = gl->mode.height - 40 - sfText_getPosition(gl->result[len - 1]).y
        - sfText_getLocalBounds(gl->result[len - 1]).height;
    if (offset <= gl->mode.height - 40)
        return;
    for (int i = 0; gl->result[i] != 0; i++){
        to_update = sfText_getPosition(gl->result[i]);
        to_update.y += offset;
        sfText_setPosition(gl->result[i], to_update);
    }
    gl->scroll_pos = 0;
}

void scroll_up(globals_t *gl)
{
    sfVector2f to_update;
    int len = my_len(gl->result);
    float offset = sfText_getLocalBounds(gl->result[len - 2]).height
        + sfText_getLocalBounds(gl->result[len - 1]).height + 10;
    float max = sfText_getLocalBounds(gl->result[len - 1]).height +
        sfText_getPosition(gl->result[len - 1]).y;

    if (max < gl->mode.height - 40)
        return ;
    for (int i = 0; gl->result[i] != 0; i++){
        to_update = sfText_getPosition(gl->result[i]);
        to_update.y -= offset;
        sfText_setPosition(gl->result[i], to_update);
    }
}
