/*
** EPITECH PROJECT, 2019
** rotate
** File description:
** rotate all
*/

#include <stddef.h>
#include "pushswap.h"

void rra(cont_t *cont)
{
    int buff_index = cont->buff_index;

    cont->tail->next = cont->head;
    cont->head->prev = cont->tail;
    cont->head = cont->tail;
    cont->tail = cont->tail->prev;
    cont->tail->next = NULL;
    cont->buffer[buff_index] = 'r';
    cont->buffer[buff_index+1] = 'r';
    cont->buffer[buff_index+2] = 'a';
    cont->buffer[buff_index+3] = ' ';
    cont->buff_index = cont->buff_index + 4;
}
