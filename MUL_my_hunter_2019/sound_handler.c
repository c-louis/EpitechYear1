/*
** EPITECH PROJECT, 2019
** sound_handler
** File description:
** part of the sound functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void add_sound(glg_t *gl, sfSound *sound)
{
    int i = 0;
    while (gl->sounds->oldsounds[i] != 0)
        i++;
    sfSound **new_oldsound = malloc(sizeof(sfSound *) * (i+2));
    for (int y = 0; y < i; y++)
        new_oldsound[y] = gl->sounds->oldsounds[y];
    new_oldsound[i] = sound;
    new_oldsound[i + 1] = 0;
    free(gl->sounds->oldsounds);
    gl->sounds->oldsounds = new_oldsound;
}

void remove_sound(glg_t *gl)
{
    int i = 0;
    while (gl->sounds->oldsounds[i] != 0)
        i++;
    if (i >= 50) {
        int y = 0;
        while (gl->sounds->oldsounds[y] != 0) {
            if (sfSound_getStatus(gl->sounds->oldsounds[y]) == sfStopped)
                sfSound_destroy(gl->sounds->oldsounds[y]);
            y++;
        }
        free(gl->sounds->oldsounds);
        sfSound **oldsound = malloc(sizeof(sfSound *));
        oldsound[0] = 0;
        gl->sounds->oldsounds = oldsound;
    }
}

void handle_shoot_sound(glg_t *gl)
{
    sfSound *shoot = sfSound_create();
    sfSound_setBuffer(shoot, sfSound_getBuffer(gl->sounds->shoot));
    sfSound_play(shoot);
    add_sound(gl, shoot);
}

void handle_hit_sound(glg_t *gl)
{
    sfSound *hit_s = sfSound_create();
    sfSound_setBuffer(hit_s, sfSound_getBuffer(gl->sounds->hit_s));
    sfSound_play(hit_s);
    add_sound(gl, hit_s);
}
