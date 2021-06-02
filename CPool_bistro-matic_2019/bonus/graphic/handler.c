/*
** EPITECH PROJECT, 2019
** visual-bistro
** File description:
** Event handling functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"
#include "eval.h"

char *carriage(char *src)
{
    int n = 18;
    int len = my_strlen(src);
    char *res = malloc(len + len / n + 1);

    for (int i = 0; src[i] != 0; i++){
        res[i + i / n] = src[i];
        if (i % n == 0 && i != 0)
            res[i] = '\n';
    }
    res[len + len / n] = '\0';
    return (res);
}

int count_carriage(char const *str)
{
    int counter = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            counter++;
    return (counter);
}

int my_len(sfText **thing)
{
    int i = 0;

    for (; thing[i] != 0; i++);
    return (i);
}

float get_posy(globals_t *gl, int len)
{
    float h;
    float y;
    float res = 20;

    for (int i = 0; i < len; i++){
        h = sfText_getLocalBounds(gl->result[i]).height;
        y = sfText_getPosition(gl->result[i]).y;
        if (h + y >= 0)
            res += h + (y < 0 ? y : 0) + 5;
    }
    return (res);
}
