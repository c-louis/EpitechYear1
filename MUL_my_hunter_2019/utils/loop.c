/*
** EPITECH PROJECT, 2019
** main file
** File description:
** main file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void pigeon_loop(glg_t *gl)
{
    animate_pigeon(gl);
    animate_dead_pigeon(gl);
    move_pigeon(gl);
    check_pigeon(gl);
}

void game_draw_loop(sfRenderWindow *window, glg_t *gl)
{
    for (int i = 0; gl->bullets[i] != 0; i++)
        render_bullet(window, gl->bullets[i]);
    for (int i = 0; gl->pig_list[i] != 0; i++)
        sfRenderWindow_drawSprite(window, gl->pig_list[i]->sprite, 0);
    for (int i = 0; gl->dead_pigeon[i] != 0; i++)
        sfRenderWindow_drawSprite(window, gl->dead_pigeon[i]->sprite, 0);
}

void game_loop(sfRenderWindow *window, glg_t *gl)
{
    game_draw_loop(window, gl);
    sfTime elapse = sfClock_getElapsedTime(gl->gameclock);
    if ((elapse.microseconds/33333)%2 == 0) {
        pigeon_loop(gl);
        reload(gl);
    }
    if ((elapse.microseconds)%(60-gl->game->score/100) == 0) {
        add_pigeon(gl);
    }
    if ((elapse.microseconds) >= 5000000) {
        sfClock_restart(gl->gameclock);
        remove_sound(gl);
        gl->tick = 0;
    }
    set_ammo_rect(gl);
    sfRenderWindow_drawSprite(window, gl->ammo_i->sprite, 0);
    sfRenderWindow_drawText(window, gl->game->score_txt, 0);
    sfRenderWindow_drawSprite(window, gl->pointer->sprite, 0);
}

void main_loop(sfRenderWindow *window, glg_t *gl)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, gl->fond->sprite, 0);
    gl->tick = gl->tick +1;
    if (gl->game->state == 0)
        menu_loop(window, gl);
    if (gl->game->state == 1)
        game_loop(window, gl);
    if (gl->game->state == 2)
        pause_loop(window, gl);
    if (gl->game->state == 3)
        explication_loop(window, gl);
    if (gl->game->state == 4)
        credit_loop(window, gl);
    sfRenderWindow_display(window);
}
