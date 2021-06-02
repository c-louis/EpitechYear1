/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** conversion utility functions
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "my.h"
#include "inf_op.h"
#include "inf_utils.h"

char *my_int_char(int);

char *my_getnbr_base(char const *, char const *);

char *convert_number(char const *src, int a, int b, char const *base)
{
    char *tmp;
    char *res;

    tmp = my_substring(src, a, b);
    res = my_getnbr_base(tmp, base);
    free(tmp);
    return (res);
}

int is_accepted(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c == '-')
        return (1);
    return (0);
}

char *make_usable_char(char const *str)
{
    char *res;
    int len = 0;

    for (; is_accepted(str[len]); len++);
    res = malloc(len + 1);
    for (int i = 0; i < len; i++)
        res[i] = str[i];
    res[len] = '\0';
    return (res);
}

char *char_to_str(char c)
{
    char *add = malloc(2);

    add[0] = c;
    add[1] = 0;
    return (add);
}

char *convert_end(char const *src, char const *base_to, char const *op)
{
    char *copy = make_usable_char(src);
    int res_len = 0;
    char *len = my_int_char(my_strlen(base_to));
    char *res = malloc(1);
    char *tmp;
    char add[] = "?";

    while (my_compare(copy, "0") != 0){
        tmp = mod_str(copy + off(copy), len);
        self_op(&copy, len, div_str);
        add[0] = base_to[my_getnbr(tmp)];
        res = append_str(res, add);
        free(tmp);
        res_len++;
    }
    if (src[0] == '-')
        res = append_str(res, char_to_str(op[OP_SUB_IDX]));
    res[res_len + off(src)] = 0;
    res = my_revstr(res);
    return (src[off(src)] == '0' ? char_to_str(base_to[0]) : res);
}
