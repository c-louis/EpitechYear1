/*
** EPITECH PROJECT, 2019
** my_find_node
** File description:
** find a specific node
*/

#include "mylist.h"
#include <stddef.h>

linked_list_t *my_find_node(linked_list_t const *begin,
                            void const *data_ref, int (*cmp)())
{
    while (begin->next != NULL) {
        if ((*cmp)(begin->data, data_ref) == 0) {
            linked_list_t *item = begin;
            return (begin);
        }
        begin = begin->next;
    }
}
