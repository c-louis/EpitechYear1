/*
** EPITECH PROJECT, 2019
** infinite sub source
** File description:
** source file for the infinite sub
*/

#include "my.h"
#include "infinite.h"
#include <stdlib.h>

void set_mid(char *result, int to_sub, int max)
{
    for (int k = max; k > 0; k--) {
        if (result[k] >= '1') {
            result[k] = result[k] + -1;
            break;
        }
        else {
            if (to_sub < 0) {
                to_sub = to_sub * -1;
            }
            result[k] = 10 - to_sub + 48;
            to_sub = 1;
        }
    }
}

void set_mem(char *result, char *nbr)
{
    result[0] = '0';
    for (int m = 1; m < my_strlen(nbr) + 2; m++)
        result[m] = nbr[m - 1];
    result[my_strlen(nbr) + 1] = '\0';
}

char *infinite_sub(char *nbr1, char *nbr2)
{
    int i = my_strlen(nbr1);
    int j = my_strlen(nbr2);
    int max = (i < j) ? j : i;
    int max_sub = (i < j) ? i : j;
    char *result  = malloc(max + 2);
    set_mem(result, ((i < j) ? nbr2 : nbr1));
    char *subnum = subnum = (i < j) ? nbr1 : nbr2;
    while (max_sub > 0) {
        int to_sub = result[max] - subnum[max_sub - 1];
        if (to_sub < 0) {
            set_mid(result, to_sub, max);
        } else {
            result[max] = to_sub + 48;
        }
        max--;
        max_sub--;
    }
    return (result);
}
