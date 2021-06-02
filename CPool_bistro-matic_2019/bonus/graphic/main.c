/*
** EPITECH PROJECT, 2019
** visual-bistro
** File description:
** main file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"

void draw_result(sfRenderWindow *window, sfText *text, globals_t *gl)
{
    float size = sfText_getLocalBounds(text).height + 2;
    sfVector2f pos = sfText_getPosition(text);

    if (pos.y >= 20 && pos.y + 20 <= gl->mode.height - 40)
        sfRenderWindow_drawText(window, text, 0);
}

void main_loop(sfRenderWindow *window, globals_t *gl)
{
    blinker(gl);
    if (gl->is_updating){
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, gl->pix, 0);
        sfRenderWindow_drawText(window, gl->in, 0);
        draw_topbar_text(gl, window);
        for (int i = 0; gl->result[i] != 0; i++)
            draw_result(window, gl->result[i], gl);
        gl->is_updating ^= 1;
    }
    sfRenderWindow_display(window);
}

void cleanup_memory(sfEvent *event, sfRenderWindow *window, globals_t *gl)
{
    cleanup_framebuffer(gl);
    sfText_destroy(gl->in);
    for (int i = 0; gl->result[i] != 0; i++)
        sfText_destroy(gl->result[i]);
    sfFont_destroy(gl->font);
    free(event);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfEvent *event = malloc(sizeof(sfEvent));
    globals_t gl;

    init_globals(&gl);
    init_window(&gl);
    window = sfRenderWindow_create(gl.mode, "Bistro-matic", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, event))
            process_event(window, event, &gl);
        main_loop(window, &gl);
    }
    cleanup_memory(event, window, &gl);
    return (0);
}
