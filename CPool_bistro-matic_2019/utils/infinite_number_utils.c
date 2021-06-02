/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** utils function used in main
*/

#include <stdlib.h>
#include "my.h"

void my_memreset(char *s, int len)
{
    for (int i = 0; i < len; i++){
        s[i] = '0';
    }
    s[len - 1] = 0;
}

int my_nbrlen(char *s)
{
    int a = my_strlen(s);

    if (s[0] == '-')
        a--;
    return (a);
}

int my_compare(char *a, char *b)
{
    int start_a = a[0] == '-' ? 1 : 0;
    int start_b = b[0] == '-' ? 1 : 0;
    int len_a = my_nbrlen(a);
    int len_b = my_nbrlen(b);

    if (len_a != len_b)
        return (len_a - len_b);
    for (int i = 0; i < len_a; i++){
        if (a[i + start_a] != b[i + start_b])
            return (a[i + start_a] - b[i + start_b]);
    }
    return (0);
}

int get_op(char *a, char *b)
{
    int op = 1;

    if (a[0] == '-')
        op *= -1;
    if (b[0] == '-')
        op *= -1;
    return (op);
}

char *neg_shift(char *res)
{
    char *copy;

    copy = my_strdup(res);
    my_strcpy(res + 1, copy);
    res[0] = '-';
    free(copy);
    return (res);
}
