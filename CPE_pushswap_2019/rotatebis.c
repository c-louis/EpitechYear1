/*
** EPITECH PROJECT, 2019
** rotatebis
** File description:
** rotatebis
*/

#include <stddef.h>
#include "pushswap.h"

void ra(cont_t *cont_a)
{
    int buff_index = cont_a->buff_index;
    lnb_t *tmp = cont_a->head;
    cont_a->head = cont_a->head->next;
    cont_a->tail->next = tmp;
    tmp->prev = cont_a->tail;
    tmp->next = NULL;
    cont_a->head->prev = NULL;
    cont_a->tail = tmp;
    cont_a->buffer[buff_index] = 'r';
    cont_a->buffer[buff_index+1] = 'a';
    cont_a->buffer[buff_index+2] = ' ';
    cont_a->buff_index = cont_a->buff_index + 3;
}
