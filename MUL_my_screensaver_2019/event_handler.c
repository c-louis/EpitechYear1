/*
** EPITECH PROJECT, 2019
** event handler
** File description:
** handle all the event
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

void dispatch_focus_event(sfRenderWindow *window, sfEvent *event)
{
    switch (event->type) {
    case sfEvtClosed:
        sfRenderWindow_close(window);
        break;
    case sfEvtLostFocus:
        sfRenderWindow_setFramerateLimit(window, 1);
        break;
    case sfEvtGainedFocus:
        sfRenderWindow_setFramerateLimit(window, 60);
        break;
    default:
        break;
    }
}

void key_pressed(sfEvent *event, glmul_t *gl)
{
    if (event->key.code == sfKeyLeft) {
        cleanup_framebuffer(gl);
        gl->anim = gl->anim - 1;
        if (gl->anim < 0)
            gl->anim = 0;
    }
    else if (event->key.code == sfKeyRight) {
        cleanup_framebuffer(gl);
        gl->anim = gl->anim + 1;
        if (gl->anim > 4)
            gl->anim = 0;
    }
}

void process_event(sfRenderWindow *window, sfEvent *event, glmul_t *gl)
{
    switch (event->type){
    case sfEvtClosed:
    case sfEvtLostFocus:
    case sfEvtGainedFocus:
        dispatch_focus_event(window, event);
        break;
    case sfEvtKeyPressed:
        key_pressed(event, gl);
        break;
    default:
        break;
    }
}
