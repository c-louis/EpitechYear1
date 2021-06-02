/*
** EPITECH PROJECT, 2019
** event_dispatcher
** File description:
** dispatch all the event
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
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
    }
}

void process_event(sfRenderWindow *window, sfEvent *event, globals_t *gl)
{
    switch (event->type){
    case (sfEvtClosed || sfEvtLostFocus || sfEvtGainedFocus):
        dispatch_focus_event(window, event);
        break;
    case sfEvtTextEntered:
        text_entered(event->text.unicode, gl);
        break;
    case sfEvtKeyPressed:
        key_pressed(event->key.code, gl);
        break;
    case sfEvtMouseWheelScrolled:
        scroll(event->mouseWheelScroll.delta, gl);
        break;
    case sfEvtMouseButtonPressed:
        clear(event, gl);
        break;
    }
}
