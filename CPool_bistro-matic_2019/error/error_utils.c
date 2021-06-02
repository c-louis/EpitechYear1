/*
** EPITECH PROJECT, 2019
** error_utils
** File description:
** utils function for errors
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"
#include "error.h"

int is_operator_base(char c, char *opbase)
{
    for (int i = 0; i < my_strlen(opbase); i++) {
        if (c == opbase[i])
            return (1);
    }
    return (0);
}
