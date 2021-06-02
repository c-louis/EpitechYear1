/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** infinite substraction function
*/

#include "inf_op.h"
#include "my.h"
#include "inf_utils.h"
#include <stdlib.h>

char *sub_str(char *a, char *b)
{
    int len = my_strlen(b);
    char *neg = malloc(len + 2);

    my_strcpy(neg, b);
    neg[len] = '\0';
    neg_shift(neg);
    return (add_str(a, neg));
}
