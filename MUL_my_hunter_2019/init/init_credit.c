/*
** EPITECH PROJECT, 2019
** init credit
** File description:
** init credit
*/


#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void set_all_policy_size(glg_t *gl)
{
    sfText_setFont(gl->credit->title, gl->bitwonder);
    sfText_setFont(gl->credit->fond, gl->arial);
    sfText_setFont(gl->credit->pigeon, gl->arial);
    sfText_setFont(gl->credit->shoot, gl->arial);
    sfText_setFont(gl->credit->death, gl->arial);
    sfText_setFont(gl->credit->impact, gl->arial);
    sfText_setCharacterSize(gl->credit->title, 20);
    sfText_setCharacterSize(gl->credit->fond, 20);
    sfText_setCharacterSize(gl->credit->pigeon, 20);
    sfText_setCharacterSize(gl->credit->shoot, 20);
    sfText_setCharacterSize(gl->credit->death, 20);
    sfText_setCharacterSize(gl->credit->impact, 20);
    sfText_setColor(gl->credit->title, sfWhite);
    sfText_setColor(gl->credit->fond, sfWhite);
    sfText_setColor(gl->credit->pigeon, sfWhite);
    sfText_setColor(gl->credit->shoot, sfWhite);
    sfText_setColor(gl->credit->death, sfWhite);
    sfText_setColor(gl->credit->impact, sfWhite);
}

void set_all_position(glg_t *gl)
{
    sfVector2f pos_title = {625, 225};
    sfVector2f pos_fond = {415, 350};
    sfVector2f pos_pigeon = {415, 400};
    sfVector2f pos_shoot = {415, 450};
    sfVector2f pos_death = {415, 500};
    sfVector2f pos_impact = {415, 550};

    sfText_setPosition(gl->credit->title, pos_title);
    sfText_setPosition(gl->credit->fond, pos_fond);
    sfText_setPosition(gl->credit->pigeon, pos_pigeon);
    sfText_setPosition(gl->credit->shoot, pos_shoot);
    sfText_setPosition(gl->credit->death, pos_death);
    sfText_setPosition(gl->credit->impact, pos_impact);
}

void set_all_text(glg_t *gl)
{
    sfText_setString(gl->credit->title, "Credit");
    sfText_setString(gl->credit->fond,
        "Background : http://www.fondsecran.eu/a/371584/1920/1200/o");
    sfText_setString(gl->credit->pigeon,
        "Pigeon : https://chapmanworld.com/2015/03/04/\
delphi-sprite-engine-part-3-the-sprite/");
    sfText_setString(gl->credit->shoot,
        "Shoot Sound : https://lasonotheque.org/\
detail-0397-tir-de-winchester-magnum-xtr.html");
    sfText_setString(gl->credit->death, "Death Sound : Mojang Minecraft");
    sfText_setString(gl->credit->impact,
        "Bullet Impact : https://pngimage.net/impact-balle-png-1/");
}

void init_all_text(glg_t *gl)
{
    gl->credit->title = sfText_create();
    gl->credit->fond = sfText_create();
    gl->credit->pigeon = sfText_create();
    gl->credit->shoot = sfText_create();
    gl->credit->death = sfText_create();
    gl->credit->impact = sfText_create();
    set_all_policy_size(gl);
    set_all_position(gl);
    set_all_text(gl);
}

void init_credit(glg_t *gl)
{
    gl->credit = malloc(sizeof(credit_t));
    init_all_text(gl);
}
