/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** put all the params in a linked list
*/

#include <stddef.h>
#include <stdlib.h>
#include "mylist.h"

int my_put_in_list(linked_list_t **list, char *arg)
{
    linked_list_t *element;
    element = malloc(sizeof(*element));
    element->data = arg;
    element->next = *list;
    *list = element;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    list = NULL;
    for (int i = 0; i < ac; i++) {
        my_put_in_list(&list, av[i]);
    }
    return (list);
}
