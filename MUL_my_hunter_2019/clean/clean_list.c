/*
** EPITECH PROJECT, 2019
** clean list
** File description:
** clean the list of the memory
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "graph.h"

void clean_pigeon_list(glg_t *gl)
{
    pigeon_t **pig_list = gl->pig_list;
    pigeon_t **dead_pigeon = gl->dead_pigeon;
    for (int i = 0; pig_list[i] != 0; i++) {
        sfSprite_destroy(pig_list[i]->sprite);
        free(pig_list[i]);
    }
    free(pig_list);
    for (int i = 0; dead_pigeon[i] != 0; i++) {
        sfSprite_destroy(dead_pigeon[i]->sprite);
        free(dead_pigeon[i]);
    }
    free(dead_pigeon);
}

void clean_sounds(glg_t *gl)
{
    sfSoundBuffer_destroy(gl->hit_sb);
    sfSoundBuffer_destroy(gl->shoot_sb);
    sfSound_destroy(gl->sounds->shoot);
    sfSound_destroy(gl->sounds->hit_s);
    for (int i = 0; gl->sounds->oldsounds[i] != 0; i++) {
        sfSound_destroy(gl->sounds->oldsounds[i]);
    }
    free(gl->sounds->oldsounds);
    free(gl->sounds);
}

void clean_bullet(glg_t *gl)
{
    bullet_t **bullets = gl->bullets;
    for (int i = 0; bullets[i] != 0; i++) {
        sfSprite_destroy(bullets[i]->impact);
        free(bullets[i]);
    }
    free(bullets);
}
