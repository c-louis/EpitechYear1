/*
** EPITECH PROJECT, 2019
** handle score function
** File description:
** score
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "graph.h"

void my_memset(char *src, int size)
{
    for (int i = 0; i < size; i++) {
        src[i] = '\0';
    }
}

void update_score(glg_t *gl, int to_add)
{
    if (gl->game->score == 0 && to_add < 0)
        return;
    gl->game->score = gl->game->score + to_add;
    int size = get_nbrsize(gl->game->score);
    char *score = malloc(sizeof(char)*(10+size));
    my_memset(score, 10+size);
    my_strcat(score, "score  ");
    my_strcat(score, my_int_char(gl->game->score));
    sfText_setString(gl->game->score_txt, score);
    free(score);
}
