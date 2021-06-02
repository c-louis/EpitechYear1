/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** screensaver animation rendering in a CSFML window
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "my.h"

void loop(sfRenderWindow *window, glmul_t *gl)
{
    sfRenderWindow_clear(window, sfBlack);
    if (gl->anim >= 1 && gl->anim <= 4) {
        circle_anim(gl);
    }
    if (gl->anim == 0) {
        line_anim(gl);
    }
    update_sprite_from_framebuffer(gl);
    sfRenderWindow_drawSprite(window, gl->sprite, 0);
    sfRenderWindow_display(window);
}

void main_graph(glmul_t *gl)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1600, 1000, 32};
    sfEvent *event = malloc(sizeof(sfEvent));
    sfClock *clock = sfClock_create();

    init_all(gl);
    window = sfRenderWindow_create(mode,  "ScreenSaver", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 2);
    gl->clock = clock;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            process_event(window, event, gl);
        }
        loop(window, gl);
    }
}

void manage_arg(glmul_t *gl, char **av)
{
    if (my_str_isnum(av[1]))
        gl->anim = my_getnbr(av[1]);
}
int main(int ac, char **av)
{
    glmul_t *gl = malloc(sizeof(glmul_t));
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0)
            print_help();
        else if (my_strcmp(av[1], "-d") == 0)
            print_details();
        else {
            manage_arg(gl, av);
            main_graph(gl);
        }
    } else {
        my_printf("./my_screensaver: bad arguments: 0 given but 1 is required");
        my_printf("\nRetry with -h\n");
    }
    return (0);
}
