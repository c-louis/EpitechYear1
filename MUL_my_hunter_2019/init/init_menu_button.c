/*
** EPITECH PROJECT, 2019
** init all the menu button
** File description:
** button for the menu initialization function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void init_menu_startbutton(glg_t *gl)
{
    sfVector2f size = {350, 70};
    sfVector2f pos = {625, 350};
    sfVector2f pos_txt = {725, 365};

    gl->menu->start_button = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->menu->start_button, sfBlack);
    sfRectangleShape_setOutlineColor(gl->menu->start_button, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->menu->start_button, 5);
    sfRectangleShape_setSize(gl->menu->start_button, size);
    sfRectangleShape_setPosition(gl->menu->start_button, pos);
    gl->menu->start_txt = sfText_create();
    sfText_setFont(gl->menu->start_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->start_txt, 30);
    sfText_setString(gl->menu->start_txt, "start");
    sfText_setPosition(gl->menu->start_txt, pos_txt);
    sfText_setColor(gl->menu->start_txt, sfWhite);
}

void init_menu_pausebutton(glg_t *gl)
{
    sfVector2f resume_pos = {700, 365};
    sfVector2f header_pos = {675, 275};

    gl->menu->pause_txt = sfText_create();
    gl->menu->resume_txt = sfText_create();
    sfText_setFont(gl->menu->pause_txt, gl->bitwonder);
    sfText_setFont(gl->menu->resume_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->pause_txt, 30);
    sfText_setCharacterSize(gl->menu->resume_txt, 30);
    sfText_setString(gl->menu->pause_txt, "* pause *");
    sfText_setString(gl->menu->resume_txt, "resume");
    sfText_setPosition(gl->menu->pause_txt, header_pos);
    sfText_setPosition(gl->menu->resume_txt, resume_pos);
    sfText_setColor(gl->menu->pause_txt, sfWhite);
    sfText_setColor(gl->menu->resume_txt, sfWhite);
}

void init_menu_exitbutton(glg_t *gl)
{
    sfVector2f size = {350, 70};
    sfVector2f pos = {625, 650};
    sfVector2f pos_txt = {750, 665};

    gl->menu->exit_button = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->menu->exit_button, sfBlack);
    sfRectangleShape_setOutlineColor(gl->menu->exit_button, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->menu->exit_button, 5);
    sfRectangleShape_setSize(gl->menu->exit_button, size);
    sfRectangleShape_setPosition(gl->menu->exit_button, pos);
    gl->menu->exit_txt = sfText_create();
    sfText_setFont(gl->menu->exit_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->exit_txt, 30);
    sfText_setString(gl->menu->exit_txt, "exit");
    sfText_setPosition(gl->menu->exit_txt, pos_txt);
    sfText_setColor(gl->menu->exit_txt, sfWhite);
}

void init_menu_creditbutton(glg_t *gl)
{
    sfVector2f size = {350, 70};
    sfVector2f pos = {625, 550};
    sfVector2f pos_txt = {720, 565};

    gl->menu->credit_button = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->menu->credit_button, sfBlack);
    sfRectangleShape_setOutlineColor(gl->menu->credit_button, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->menu->credit_button, 5);
    sfRectangleShape_setSize(gl->menu->credit_button, size);
    sfRectangleShape_setPosition(gl->menu->credit_button, pos);
    gl->menu->credit_txt = sfText_create();
    sfText_setFont(gl->menu->credit_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->credit_txt, 30);
    sfText_setString(gl->menu->credit_txt, "credit");
    sfText_setPosition(gl->menu->credit_txt, pos_txt);
    sfText_setColor(gl->menu->credit_txt, sfWhite);
}

void init_menu_explibutton(glg_t *gl)
{
    sfVector2f size = {350, 70};
    sfVector2f pos = {625, 450};
    sfVector2f pos_txt = {700, 465};

    gl->menu->expli_button = sfRectangleShape_create();
    sfRectangleShape_setFillColor(gl->menu->expli_button, sfBlack);
    sfRectangleShape_setOutlineColor(gl->menu->expli_button, sfWhite);
    sfRectangleShape_setOutlineThickness(gl->menu->expli_button, 5);
    sfRectangleShape_setSize(gl->menu->expli_button, size);
    sfRectangleShape_setPosition(gl->menu->expli_button, pos);
    gl->menu->expli_txt = sfText_create();
    sfText_setFont(gl->menu->expli_txt, gl->bitwonder);
    sfText_setCharacterSize(gl->menu->expli_txt, 30);
    sfText_setString(gl->menu->expli_txt, "tutorial");
    sfText_setPosition(gl->menu->expli_txt, pos_txt);
    sfText_setColor(gl->menu->expli_txt, sfWhite);
}
