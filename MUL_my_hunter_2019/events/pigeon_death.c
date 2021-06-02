/*
** EPITECH PROJECT, 2019
** pigeon_death
** File description:
** die
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void add_bullet(glg_t *gl, bullet_t *bullet)
{
    int i = 0;
    while (gl->bullets[i] != 0)
        i++;
    bullet_t **new_bulletlist = malloc(sizeof(bullet_t *) * (i+2));
    for (int y = 0; y < i; y++)
        new_bulletlist[y] = gl->bullets[y];
    new_bulletlist[i] = bullet;
    new_bulletlist[i + 1] = 0;
    free(gl->bullets);
    gl->bullets = new_bulletlist;
}

void handle_shoot_bullet(glg_t *gl, sfMouseButtonEvent data)
{
    sfSprite *bullet = sfSprite_create();
    sfVector2f scale = {0.10, 0.10};
    sfVector2f pos = {data.x - 25, data.y - 25};
    sfSprite_setTexture(bullet, gl->bullet_texture, 0);
    sfSprite_setScale(bullet, scale);
    sfSprite_setPosition(bullet, pos);
    bullet_t *new_bullet = malloc(sizeof(bullet_t));
    new_bullet->impact = bullet;
    new_bullet->display_time = 0;
    add_bullet(gl, new_bullet);
}

void kill_pigeon(glg_t *gl, int killed)
{
    handle_hit_sound(gl);
    add_dead_pigeon(gl, gl->pig_list[killed]);
    remove_pigeon(gl, killed);
    update_score(gl, 10);
}

void check_hit_pos(sfMouseButtonEvent data, glg_t *gl)
{
    int hit = -1;
    for (int i = 0; gl->pig_list[i] != 0; i++) {
        pigeon_t *pigeon = gl->pig_list[i];
        sfIntRect cursor_zone = {data.x-10, data.y-10, 20, 20};
        if (sfIntRect_intersects(&(pigeon->hitbox),
            &cursor_zone, 0) == sfTrue) {
            hit = i;
            break;
        }
    }
    if (hit != -1) {
        kill_pigeon(gl, hit);
        check_hit_pos(data, gl);
    } else {
        update_score(gl, -1);
    }
}
