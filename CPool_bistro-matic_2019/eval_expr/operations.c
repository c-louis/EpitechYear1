/*
** EPITECH PROJECT, 2019
** operation
** File description:
** operation thing
*/

#include "my.h"
#include "eval.h"
#include "inf_op.h"
#include <stdlib.h>
#include <stdio.h>

char *factors(char **str)
{
    char *endptr = malloc(my_strlen(*str) + 1);
    my_strcpy(endptr, *str);
    char *f_num = my_strtol(*str, &endptr);
    char operator = get_operator(&endptr);
    char *s_num = my_strtol(endptr, &endptr);
    (f_num[0] == '+') ? f_num++ : 0;
    if (my_strlen(s_num) == 0)
        return (f_num);
    if (operator == '*')
        return (mul_str(f_num, s_num));
    if (*s_num == '0') {
        my_putstr("error");
        exit(84);
    }
    if (operator == '/')
        return (div_str(f_num, s_num));
    if (operator == '%')
        return (mod_str(f_num, s_num));
    return (f_num);
}

char *summands(char **str)
{
    char *endptr = malloc(my_strlen(*str) + 1);
    my_strcpy(endptr, *str);
    char *f_num = my_strtol(*str, &endptr);
    char operator = get_operator(&endptr);
    char *s_num = my_strtol(endptr, &endptr);
    (f_num[0] == '+') ? f_num++ : 0;
    if (my_strlen(s_num) == 0)
        return (f_num);
    if (my_strlen(f_num) == 0)
        return (s_num);
    if (operator == '-' && f_num[0] == '-' && s_num[0] == '-')
        return (add_str(f_num, s_num + 1));
    if (operator == '+')
        return (add_str(f_num, s_num));
    if (operator == '-')
        return (sub_str(f_num, s_num));
    return (f_num);
}
