/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** square drawing utilities
*/

#include <SFML/Graphics.h>
#include "graph.h"

void draw_square(framebuffer_t *fb, sfVector2u pos, int size, sfColor c)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            put_pixel(fb, pos.x + i, pos.y + j, c);
        }
    }
}

void draw_rect(framebuffer_t *fb, sfIntRect rect, sfColor c)
{
    for (int i = 0; i < rect.width; i++){
        for (int j = 0; j < rect.height; j++){
            put_pixel(fb, rect.left + i, rect.top + j, c);
        }
    }
}

void draw_borders(framebuffer_t *fb, sfIntRect rect, int margin, sfColor c)
{
    sfIntRect inside = {rect.left + margin, rect.top + margin,
        rect.width - 2 * margin, rect.height - 2 * margin};
    draw_rect(fb, rect, c);
    draw_rect(fb, inside, sfWhite);
}
