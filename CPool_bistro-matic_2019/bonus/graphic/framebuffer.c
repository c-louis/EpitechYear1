/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** framebuffer utilities
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
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

    fb->pixels[pos + 0] = color.r;
    fb->pixels[pos + 1] = color.g;
    fb->pixels[pos + 2] = color.b;
    fb->pixels[pos + 3] = color.a;
}

void cleanup_framebuffer(globals_t *gl)
{
    free(gl->fb->pixels);
    free(gl->fb);
    sfImage_destroy(gl->image);
    sfTexture_destroy(gl->tex);
    sfSprite_destroy(gl->pix);
}

sfSprite *create_sprite_from_framebuffer(globals_t *gl, sfVideoMode *mode)
{
    if (gl->init){
        sfImage_destroy(gl->image);
        sfTexture_destroy(gl->tex);
        sfSprite_destroy(gl->pix);
    }else{
        gl->init ^= 1;
    }
    int size = 0;
    gl->image = sfImage_createFromPixels(gl->mode.width,
    gl->mode.height,
    gl->fb->pixels);
    gl->tex = sfTexture_createFromImage(gl->image, 0);
    gl->pix = sfSprite_create();
    sfSprite_setTexture(gl->pix, gl->tex, sfTrue);
    return (gl->pix);
}
