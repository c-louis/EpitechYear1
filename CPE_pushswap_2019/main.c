/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** pushswap
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

int is_sorted(lnb_t *l_a)
{
    lnb_t *tmp = l_a;
    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL) {
        if (tmp->nb > tmp->next->nb)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void check_buffer(cont_t *cont)
{
    if (cont->buff_index >= 4093) {
        write(1, cont->buffer, cont->buff_index);
        cont->buff_index = 0;
    }
}

void sort_gnome(cont_t *l_a)
{
    int ra_count = 0;
    int last = 0;
    while (1) {
        lnb_t *list = l_a->head;
        check_buffer(l_a);
        if (ra_count == 0 && is_sorted(list) == 1)
            break;
        if (list->nb > list->next->nb) {
            sa(l_a);
            last = 1;
        } else if (ra_count > 0 && last == 1) {
            rra(l_a);
            ra_count--;
        } else {
            ra(l_a);
            ra_count++;
            last = 0;
        }
    }
    write(1, l_a->buffer, l_a->buff_index-1);
}

int main(int ac, char **av)
{
    cont_t *cont_a = malloc(sizeof(cont_t));
    cont_a->head = NULL;
    cont_a->tail = NULL;
    if (ac < 2) {
        return (84);
    } else if (ac == 2) {
        write(1, "\n", 1);
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        lnb_t *new_node = create_node(av[i]);
        if (new_node == NULL)
            return (84);
        add_node_end(cont_a, new_node);
    }
    if (is_sorted(cont_a->head)) {
        write(1, "\n", 1);
        return (0);
    }
    sort_gnome(cont_a);
    write(1, "\n", 1);
}
