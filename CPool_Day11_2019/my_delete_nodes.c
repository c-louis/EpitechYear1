/*
** EPITECH PROJECT, 2019
** my_delete_nodes
** File description:
** delete a specific node
*/

#include "mylist.h"
#include <stddef.h>

int find_data_ref(linked_list_t *begin, void const *data_ref, int (*cmp)())
{
    int i = 0;
    while (begin->next != NULL) {
        if ((*cmp)(begin->data, data_ref) == 0) {
            return (i);
        }
        i++;
    }
    return (0);
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    /**
    int data_index = find_data_ref(*begin, data_ref);
    for (int i = 0; i < data_index - 1; i++) {
        *begin = *begin->next;
    }
    *begin->next = *begin->next->next;
    return (0);
    **/
}
