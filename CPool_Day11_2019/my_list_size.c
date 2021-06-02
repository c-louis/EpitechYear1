/*
** EPITECH PROJECT, 2019
** my_list_size
** File description:
** get the size of the list
*/

#include <stddef.h>
#include <stdio.h>
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;
    while (begin != NULL) {
        begin = begin->next;
        i++;
    }
    return (i);
}
