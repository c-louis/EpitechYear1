/*
** EPITECH PROJECT, 2019
** position sort
** File description:
** sort function
*/

#include <stddef.h>
#include "pushswap.h"

void pa(lnb_t *l_a, lnb_t *l_b)
{
    if (l_b == NULL)
        return;
    lnb_t *tmp = l_a->next;
    l_a = l_b;
    l_a->next = tmp;
    l_b = l_b->next;
}

void pb(lnb_t *l_b, lnb_t *l_a)
{
    if (l_b == NULL)
        return;
    lnb_t *tmp = l_a->next;
    l_a = l_b;
    l_a->next = tmp;
    l_b = l_b->next;
}
