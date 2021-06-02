/*
** EPITECH PROJECT, 2019
** node
** File description:
** node handling
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"
#include "my.h"

lnb_t *create_node(char *cnb)
{
    int nb = my_getnbr(cnb);
    lnb_t *node = malloc(sizeof(lnb_t));

    if (node == NULL)
        return (NULL);
    node->nb = nb;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void add_node_end(cont_t *cont, lnb_t *node)
{
    if (cont->head == NULL) {
        cont->head = node;
        cont->tail = node;
        cont->size = cont->size + 1;
        return;
    }
    lnb_t *tail = cont->tail;
    tail->next = node;
    node->prev = tail;
    cont->tail = node;
    cont->size = cont->size + 1;
}
