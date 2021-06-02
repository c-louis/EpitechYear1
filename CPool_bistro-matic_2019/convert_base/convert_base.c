/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Convert from format to format
*/

#include "my.h"
#include "inf_utils.h"
#include <stdio.h>
#include <stdlib.h>

char *my_getnbr_base(char const *str, char const *base);

char *append_str(char *dest, char const *to_add);

char *convert_number(char const *src, int a, int b, char const *base);

int get_base(char c, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++){
        if (c == base[i])
            return (i);
    }
    return (-1);
}

char *replace_operator(char c, char const *op)
{
    switch (get_base(c, op)){
    case 0:
        return ("(");
    case 1:
        return (")");
    case 2:
        return ("+");
    case 3:
        return ("-");
    case 4:
        return ("*");
    case 5:
        return ("/");
    case 6:
        return ("%");
    }
    return ("?");
}

char *convert_bistro(char const *src, char const *base, char const *op)
{
    char *res = malloc(1);
    char *tmp;
    int starting_index = -1;

    res[0] = '\0';
    for (int i = 0; i < my_strlen(src) + 1; i++){
        if (get_base(src[i], base) >= 0 && starting_index < 0)
            starting_index = i;
        if (get_base(src[i], base) < 0 && starting_index >= 0){
            tmp = convert_number(src, starting_index, i, base);
            res = append_str(res, tmp);
            free(tmp);
            starting_index = -1;
        }
        if (get_base(src[i], base) < 0 && src[i] != '\0')
            res = append_str(res, replace_operator(src[i], op));
    }
    return (res);
}
