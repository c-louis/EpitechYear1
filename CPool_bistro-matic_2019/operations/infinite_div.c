/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Division operation
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "inf_utils.h"
#include "inf_op.h"

char *my_putnegdiv(char *a, char *b, char *res)
{
    if ((a[0] == '-' && b[0] != '-')
        || (b[0] == '-' && a[0] != '-')){
        return (neg_shift(res));
    }
    return (res);
}

int count_div(char *current, char *div)
{
    int res = 0;
    int div_l = my_strlen(div);
    char *it;
    char *divisor;
    char *tmp;

    if (my_compare(current, div) < 0)
        return (0);
    it = my_strdup(current);
    divisor = malloc(my_strlen(div) + 2);
    my_strcpy(divisor, div);
    if (divisor[0] != '-')
        neg_shift(divisor);
    while (it[0] != '-'){
        tmp = add_str(it, divisor);
        free(it);
        it = tmp;
        res++;
    }
    return (res - 1);
}

char *my_subcurr(char *current, char *div, int count)
{
    char factor[3];
    char *mul;
    char *res;

    if (div[0] != '-'){
        factor[0] = '-';
        factor[1] = count + 48;
        factor[2] = '\0';
    }else {
        factor[0] = count + 48;
        factor[1] = '\0';
    }
    mul = mul_str(div, factor);
    res = add_str(current, mul);
    free(current);
    return (get_starting_pointer(res));
}

char *append_curr(char *curr, char to_add)
{
    int len = my_strlen(curr);

    if (curr[0] == '0'){
        curr[0] = to_add;
        curr[1] = '\0';
    }else{
        curr[len] = to_add;
        curr[len + 1] = '\0';
    }
    return (curr);
}

char *div_str(char *a, char *b)
{
    int str_l = my_nbrlen(a);
    char *curr = malloc(str_l);
    char *res = malloc(str_l + 1);
    int count = 0;

    curr[0] = '\0';
    for (int i = 0; i < str_l; i++){
        curr = append_curr(curr, a[i + off(a)]);
        count = count_div(curr, b);
        res[i] = count + '0';
        curr = my_subcurr(curr, b, count);
    }
    res[str_l] = '\0';
    res = get_starting_pointer(res);
    return (my_putnegdiv(a, b, res));
}
