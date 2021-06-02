/*
** EPITECH PROJECT, 2019
** my_rev_list
** File description:
** reverse the list item
*/

#include "mylist.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list = *begin;
    linked_list_t *tmp_next;
    linked_list_t *tmp;
    
    tmp = NULL;
    while (list->next) {
        tmp_next = list->next;
        list->next = tmp;
        tmp = list;
        list = tmp_next;
    }
    list->next = tmp;
    *begin = list;
}
