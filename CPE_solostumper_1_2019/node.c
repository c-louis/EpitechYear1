/*
** EPITECH PROJECT, 2020
** countwords
** File description:
** countwords node system
*/

#include <stdlib.h>
#include <stddef.h>

#include "countwords.h"

char_oc_t *create_node(char *word)
{
    char_oc_t *new_char = malloc(sizeof(char_oc_t));
    if (new_char == NULL)
        return NULL;
    new_char->num = 1;
    new_char->word = word;
    new_char->next = NULL;
    return (new_char);
}

void add_node_end(char_oc_t **list, char_oc_t *new_char)
{
    if (*list == NULL) {
        *list = new_char;
        return;
    }
    char_oc_t *tmp = *list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_char;
}

void free_nodes(char_oc_t *nodes)
{
    char_oc_t *tmp = nodes;

    while (nodes != NULL) {
        tmp = nodes;
        nodes = nodes->next;
        free(tmp);
    }
}
