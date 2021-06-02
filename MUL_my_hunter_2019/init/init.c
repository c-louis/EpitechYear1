/*
** EPITECH PROJECT, 2019
** init
** File description:
** init function to init all the struct
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void init_game(glg_t *gl)
{
    sfVector2f pos = {20, 950};

    gl->game = malloc(sizeof(game_stat_t));
    gl->game->score_txt = sfText_create();
    sfText_setFont(gl->game->score_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->game->score_txt, 20);
    sfText_setColor(gl->game->score_txt, sfWhite);
    sfText_setPosition(gl->game->score_txt, pos);
    gl->game->score = 0;
    gl->game->hit = 0;
    gl->game->shot_missed = 0;
    gl->game->state = 0;
    gl->game->pigeon_missed = 0;
    gl->gameclock = sfClock_create();
}

void init_sound(glg_t *gl)
{
    gl->shoot_sb = sfSoundBuffer_createFromFile("assets/sound/shoot.ogg");
    gl->hit_sb = sfSoundBuffer_createFromFile("assets/sound/hit.ogg");
    sfSound **oldsound = malloc(sizeof(sfSound *));
    gl->sounds = malloc(sizeof(sound_t));
    gl->sounds->shoot = sfSound_create();
    gl->sounds->hit_s = sfSound_create();
    sfSound_setBuffer(gl->sounds->hit_s, gl->hit_sb);
    sfSound_setBuffer(gl->sounds->shoot, gl->shoot_sb);
    oldsound[0] = 0;
    gl->sounds->oldsounds = oldsound;
}

void init_bullets(glg_t *gl)
{
    sfVector2f ammo_scale = {0.15, 0.15};
    sfVector2f pos = {1575, 975};
    gl->bullet_texture = sfTexture_createFromFile("assets/img/bullet.png", 0);
    gl->bullets = malloc(sizeof(bullet_t *));
    gl->bullets[0] = 0;
    gl->ammo_i = malloc(sizeof(image_t));
    gl->ammo_i->texture = sfTexture_createFromFile("assets/img/ammo.png", 0);
    gl->ammo_i->sprite = sfSprite_create();
    sfSprite_setScale(gl->ammo_i->sprite, ammo_scale);
    sfSprite_setRotation(gl->ammo_i->sprite, 180);
    sfSprite_setTexture(gl->ammo_i->sprite, gl->ammo_i->texture, 0);
    sfSprite_setPosition(gl->ammo_i->sprite, pos);
}

void init_pigeon(glg_t *gl)
{
    pigeon_t **pig_list = malloc(sizeof(pigeon_t *));
    pigeon_t **dead_pigeon = malloc(sizeof(pigeon_t *));

    gl->pigeon_texture = sfTexture_createFromFile("assets/img/pigeon.png", 0);
    sfTexture_setSmooth(gl->pigeon_texture, sfTrue);
    pig_list[0] = 0;
    dead_pigeon[0] = 0;
    gl->dead_pigeon = dead_pigeon;
    gl->pig_list = pig_list;
}

void init_global(glg_t *gl)
{
    init_font(gl);
    init_fond(gl);
    init_menu(gl);
    init_game(gl);
    init_pointer(gl);
    init_sound(gl);
    init_bullets(gl);
    init_pigeon(gl);
    init_explication(gl);
    init_credit(gl);
    gl->ammo = 4;
    gl->tick = 0;
}
