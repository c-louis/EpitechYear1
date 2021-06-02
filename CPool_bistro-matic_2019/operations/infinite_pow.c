/*
** EPITECH PROJECT, 2019
** infinite_pow
** File description:
** infinite power function
*/

#include <stdlib.h>
#include "my.h"
#include "inf_utils.h"
#include "inf_op.h"

char *pow_str(char *nbr, char *p)
{
    char *pow = my_strdup(p);
    char *res = malloc(2);

    res[0] = '1';
    res[1] = '\0';
    if (pow[0] == '-')
        return (add_str(res, "-1"));
    while (*pow != '0') {
        self_op(&res, nbr, mul_str);
        self_op(&pow, "-1", add_str);
    }
    free(pow);
    return (res);
}
