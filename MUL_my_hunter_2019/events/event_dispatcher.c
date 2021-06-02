/*
** EPITECH PROJECT, 2019
** event_dispatcher
** File description:
** dispatch all the event
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void process_event(sfRenderWindow *window, sfEvent *event, glg_t *gl)
{
    switch (event->type){
    case sfEvtClosed:
    case sfEvtLostFocus:
    case sfEvtGainedFocus:
        dispatch_focus_event(window, event, gl);
        break;
    case sfEvtKeyPressed:
        key_pressed(event, gl);
        break;
    case sfEvtMouseButtonPressed:
        click_handler(event, gl);
        break;
    case sfEvtMouseMoved:
        set_pointer_pos(event->mouseMove, gl);
        break;
    default:
        break;
    }
}
