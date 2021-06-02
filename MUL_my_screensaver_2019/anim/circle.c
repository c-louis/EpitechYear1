/*
** EPITECH PROJECT, 2019
** cicle
** File description:
** circle animation
*/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

void draw_circle(framebuffer_t *fb, point_t *point, int x, int y)
{
    put_pixel(fb, point->x+x, point->y+y, random_color());
    put_pixel(fb, point->x-x, point->y+y, random_color());
    put_pixel(fb, point->x+x, point->y-y, random_color());
    put_pixel(fb, point->x-x, point->y-y, random_color());
    put_pixel(fb, point->x+y, point->y+x, random_color());
    put_pixel(fb, point->x-y, point->y+x, random_color());
    put_pixel(fb, point->x+y, point->y-x, random_color());
    put_pixel(fb, point->x-y, point->y-x, random_color());
}

void move_all(glmul_t *gl, int mode)
{
    framebuffer_t *fb = gl->framebuffer;
    for (int i = (1600*1000*4); i > 0; i--) {
        if (i == 1600*1000*4) {
            fb->pixels[i] = 0;
        } else {
            fb->pixels[i+mode] = fb->pixels[i];
        }
    }
}

void circle_bressenham(glmul_t *gl, point_t *point, int r)
{
    int x = 0;
    int y = r;
    int d = 3-2*r;

    if (r <= 0)
        return;
    draw_circle(gl->framebuffer, point, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else {
            d = d + 4 * x + 6;
        }
        draw_circle(gl->framebuffer, point, x, y);
    }
    circle_bressenham(gl, point, r - (rand()%10+5));
}

void circle_anim(glmul_t *gl)
{
    point_t *point = malloc(sizeof(point_t));

    point->x = rand()%1600;
    point->y = rand()%1000;
    circle_bressenham(gl, point, rand()%200);
    if (gl->anim == 1)
        move_all(gl, 17);
    if (gl->anim == 2)
        move_all(gl, 1);
    if (gl->anim == 3)
        move_all(gl, 256);
}
