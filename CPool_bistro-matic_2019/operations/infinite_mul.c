/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Infinite multiplication program
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_utils.h"

char *my_putnegmul(char *a, char *b, char *res)
{
    if ((a[0] == '-' && b[0] != '-')
        || (b[0] == '-' && a[0] != '-')){
        return (neg_shift(res));
    }
    return (res);
}

char *my_normalize(char *res)
{
    int new;

    for (int i = my_strlen(res) - 1; i > -1; i--){
        if (res[i] == '-' && i == 0)
            continue;
        if (res[i] < '0' || res[i] > '9'){
            new = res[i] - '0';
            res[i] = (new % 10) + '0';
            res[i - 1] += new / 10;
        }
    }
    return (res);
}

char *mul_str(char *a, char *b)
{
    int a_l = my_nbrlen(a);
    int b_l = my_nbrlen(b);
    int max_l = max(a_l, b_l);
    int len = a_l + b_l;
    char *res = malloc(len + 2);

    my_memreset(res, len + 2);
    for (int i = 0; i < a_l; i++){
        for (int j = 0; j < b_l; j++){
            res[len - j - i] += ((a[a_l - i - 1 + off(a)] - '0')
                * (b[b_l - j - 1 + off(b)] - '0')) % 10;
            res[len - j - i - 1] += ((a[a_l - i - 1 + off(a)] - '0')
                * (b[b_l - j - 1 + off(b)] - '0')) / 10;
        }
        res = my_normalize(res);
    }
    res = get_starting_pointer(res);
    return (my_putnegmul(a, b, res));
}
