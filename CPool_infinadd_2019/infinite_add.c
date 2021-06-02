/*
** EPITECH PROJECT, 2019
** infinadd main
** File description:
** main for the infinadd
*/

#include "my.h"
#include "infinite.h"
#include <stdlib.h>

void subsubadd(int *j, int *i, int *k)
{
    *j = *j - 1;
    *i = *i - 1;
    *k = *k + 1;
}

char *infinite_add(char **av)
{
    int i = my_strlen(av[1]);
    int j = my_strlen(av[2]);
    int k = 0;
    int max = (i < j) ? j : i;
    char *result  = malloc(max + 2);
    my_memset(result, max);
    while (max - k > 0) {
        int to_add = result[max - k] - 48;
        if (i > 0)
            to_add += av[1][i - 1] - 48;
        if (j > 0)
            to_add += av[2][j - 1] - 48;
        if (to_add > 9) {
            to_add = to_add % 10;
            result[max - k - 1] = '1';
        }
        result[max - k] = (to_add + 48);
        subsubadd(&j, &i, &k);
    }
    return (result);
}
