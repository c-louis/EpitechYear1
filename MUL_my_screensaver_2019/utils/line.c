/*
** EPITECH PROJECT, 2019
** line management
** File description:
** line management
*/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

void check_line(line_t *line)
{
    if (line->x2 < line->x1) {
        int x1 = line->x2;
        line->x2 = line->x1;
        line->x1 = x1;
    }
    if (line->y2 < line->y1) {
        int y1 = line->y2;
        line->y2 = line->y1;
        line->y1 = y1;
    }
    if (line->x1 < 0)
        line->x1 = line->x1 * -1;
    if (line->y1 < 0)
        line->y1 = line->y1 * -1;
    if (line->x2 < 0)
        line->x2 = line->x2 * -1;
    if (line->y2 < 0)
        line->y2 = line->y2 * -1;
}

void draw_line(framebuffer_t *fb, line_t *line)
{
    check_line(line);
    int x1 = line->x1;
    int x2 = line->x2;
    int y1 = line->y1;
    int y2 = line->y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dd = 2*dy - dx;
    int y = y1;

    for (int x = x1; x < x2; x++) {
        if (dd > 0) {
            put_pixel(fb, x, y, random_color());
            y = y + 1;
            dd = dd -2*dx+2*dy;
        } else {
            put_pixel(fb, x, y, random_color());
            dd = dd+2*dy;
        }
    }
}

int get_lines_count(line_t **lines)
{
    int i = 0;
    for (i; lines[i] != 0; i++);
    return (i);
}
