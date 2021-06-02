/*
** EPITECH PROJECT, 2019
** kock snowflakes animation
** File description:
** koch animation snowflakes happy christmath
*/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

sfColor random_color(void)
{
    srand(time(0));
    if (rand()%2 == 0)
        return (sfColor_fromInteger(rand()*-1));
    return (sfColor_fromInteger(rand()));
}

void make_random_line(line_t *line)
{
    srand(time(0));
    line->x1 = ((rand()%2) == 1 ? (rand()%1600) : 0);
    line->y1 = (line->x1 == 0 ? (rand()%1000) : 0);
    line->x2 = rand()%50;
    line->y2 = rand()%50;
}

void add_random_line(glmul_t *gl)
{
    line_t **lines = gl->line_anim->lines;
    int size = get_lines_count(lines);
    line_t **new_lines = malloc(sizeof(line_t *)*(size+2));
    for (int y = 0; y < size; y++)
        new_lines[y] = lines[y];
    line_t *line = malloc(sizeof(line_t));
    make_random_line(line);
    new_lines[size] = line;
    new_lines[size + 1] = 0;
    free(gl->line_anim->lines);
    gl->line_anim->lines = new_lines;
}

void line_up(line_t **lines)
{
    for (int i = 0; lines[i] != 0; i++) {
        line_t *line = lines[i];
        sfVector2i dir = {line->x2 - line->x1, line->y2 - line->y1};
        line->x1 = line->x2;
        line->y1 = line->y2;
        line->x2 = line->x2 + dir.x;
        line->y2 = line->y2 + dir.y;
    }
}

void line_anim(glmul_t *gl)
{
    sfTime elapse = sfClock_getElapsedTime(gl->clock);
    if (elapse.microseconds > 1) {
        add_random_line(gl);
        line_up(gl->line_anim->lines);
        sfClock_restart(gl->clock);
    }
    for (int i = 0; gl->line_anim->lines[i] != 0; i++)
        draw_line(gl->framebuffer, gl->line_anim->lines[i]);
}
