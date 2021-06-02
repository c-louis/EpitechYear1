/*
** EPITECH PROJECT, 2019
** sorting function
** File description:
** sorting
*/

#include <stddef.h>
#include "pushswap.h"

void sa(cont_t *cont_a)
{
    int buff_index = cont_a->buff_index;

    if (cont_a == NULL || cont_a->head == NULL)
        return;
    if (cont_a->size < 2)
        return;
    lnb_t *l_a = cont_a->head;
    lnb_t *nb1 = l_a;
    lnb_t *nb2 = l_a->next;
    int nb = nb1->nb;
    nb1->nb = nb2->nb;
    nb2->nb = nb;
    cont_a->buffer[buff_index] = 's';
    cont_a->buffer[buff_index+1] = 'a';
    cont_a->buffer[buff_index+2] = ' ';
    cont_a->buff_index = cont_a->buff_index + 3;
}
