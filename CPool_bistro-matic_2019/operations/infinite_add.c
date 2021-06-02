/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Infinite addition program
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_utils.h"

char *my_putneg(char *a, char *b, char *res)
{
    if (a[0] != '-' && b[0] != '-')
        return (res);
    if (a[0] == '-' && b[0] == '-'){
        return (neg_shift(res));
    }
    if (my_compare(a, b) == 0)
        return (res);
    if ((a[0] == '-' && my_compare(a, b) > 0)
        || (b[0] == '-' && my_compare(b, a) > 0)){
        return (neg_shift(res));
    }
    return (res);
}

char *add_part(char *a, char *b, int op)
{
    int to_add = 0;
    int a_l = my_nbrlen(a);
    int b_l = my_nbrlen(b);
    int max_l = max(a_l, b_l);
    char *res = malloc(max_l + 3);

    my_memreset(res, max_l + 3);
    for (int i = 0; i < min(a_l, b_l); i++){
        if (a[a_l - i - 1 + off(a)] == '-' || b[b_l - i - 1 + off(b)] == '-')
            continue;
        to_add = (a[a_l - i - 1 + off(a)] - '0' + (b[b_l - i - 1 + off(b)]
            - '0') * op) * sign(my_compare(a, b), op);
        while (to_add + res[max_l - i + 1] > '9'
            || to_add + res[max_l - i + 1] < '0'){
            res[max_l - i] += op;
            to_add -= 10 * op;
        }
        res[max_l - i + 1] += to_add;
    }
    return (res);
}

char *add_str(char *a, char *b)
{
    int op = get_op(a, b);
    int a_l = my_nbrlen(a);
    int b_l = my_nbrlen(b);
    int max_l = max(a_l, b_l);
    int max_offset = a_l > b_l ? off(a) : off(b);
    char *max_str = a_l > b_l ? a : b;
    char *res = add_part(a, b, op);

    for (int i = min(a_l, b_l); i < max_l; i++){
        if (max_str[max_l - i - (1 - max_offset)] == '-')
            continue;
        res[max_l - i + 1] += max_str[max_l - i - (1 - max_offset)] - '0';
        if (res[max_l - i + 1] > '9' || res[max_l - i + 1] < '0'){
            res[max_l - i] += op;
            res[max_l - i + 1] -= 10 * op;
        }
    }
    res = get_starting_pointer(res);
    return (my_putneg(a, b, res));
}
