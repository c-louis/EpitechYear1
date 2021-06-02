/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** utils function for infinite
*/

#include <stdlib.h>
#include "my.h"

char *get_starting_pointer(char *s)
{
    int len = my_strlen(s);
    char *res = s;

    for (int i = 0; i < len; i++){
        if (s[i] != '0'){
            res = my_strncpy(res, &s[i], len - i);
            res[len - i] = '\0';
            return (res);
        }
    }
    res = my_strncpy(res, &s[len - 1], 1);
    res[1] = '\0';
    return (res);
}

char *shift_str(char *dest, int offset)
{
    char *copy;

    copy = my_strdup(dest);
    if (offset > 0)
        my_strcpy(dest + offset, copy);
    else
        my_strcpy(dest, copy - offset);
    free(copy);
    return (dest);
}

char *self_op(char **s1, char *s2, char *(op)())
{
    char *tmp;

    tmp = op(*s1, s2);
    free(*s1);
    *s1 = tmp;
    return (*s1);
}

char *my_substring(char const *str, int a, int b)
{
    char *ret = malloc(b - a + 1);

    my_strncpy(ret, str + a, b - a);
    ret[b - a] = '\0';
    return (ret);
}

char *append_str(char *dest, char const *to_add)
{
    char *copy = my_strdup(dest);

    free(dest);
    dest = malloc(my_strlen(copy) + my_strlen(to_add) + 1);
    dest[0] = 0;
    my_strcat(dest, copy);
    dest[my_strlen(copy)] = 0;
    my_strcat(dest, to_add);
    dest[my_strlen(copy) + my_strlen(to_add)] = 0;
    free(copy);
    return (dest);
}
