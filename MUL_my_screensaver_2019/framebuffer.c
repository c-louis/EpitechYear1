/*
** EPITECH PROJECT, 2019
** frame_buffer
** File description:
** framebuffer functions
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *fb;

    fb = malloc(sizeof(framebuffer_t));
    if (fb == 0)
        return (0);
    fb->pixels = malloc((sizeof(sfUint8)) * (width * height * 4));
    if (fb->pixels == 0)
        return (0);
    fb->width = width;
    fb->height = height;
    return (fb);
}

void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor color)
{
    unsigned int width = fb->width;
    unsigned int pos = (x + width * y ) * 4;
    srand(time(0));
    if (pos+0 > (1600*1000*4) || pos+1 > (1600*1000*4)
        || pos+2 > (1600*1000*4) || pos+3 > (1600*1000*4)) {
        return;
    }
    fb->pixels[pos + 0] = color.r;
    fb->pixels[pos + 1] = color.g;
    fb->pixels[pos + 2] = color.b;
    fb->pixels[pos + 3] = 255;
}

void cleanup_framebuffer(glmul_t *gl)
{
    for (int i = 0; i < (1600*1000*4); i++) {
        gl->framebuffer->pixels[i] = 0;
    }
}

void cleanup_all_framebuffer(glmul_t *gl)
{
    free(gl->framebuffer->pixels);
    free(gl->framebuffer);
    sfImage_destroy(gl->image);
    sfTexture_destroy(gl->texture);
    sfSprite_destroy(gl->sprite);
}

void update_sprite_from_framebuffer(glmul_t *gl)
{
    sfTexture_updateFromPixels(gl->texture,
        gl->framebuffer->pixels, 1600, 1000, 0, 0);
}
