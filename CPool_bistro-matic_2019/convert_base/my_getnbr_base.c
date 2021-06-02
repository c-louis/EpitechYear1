/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** returns the decimal value of an integer in base b
*/

#include <stdio.h>
#include "my.h"
#include "inf_op.h"
#include "inf_utils.h"

char *my_int_char(int);

char *get_index(char const *base, char c)
{
    for (int i = 0; base[i] != '\0'; i++){
        if (base[i] == c)
            return (my_int_char(i));
    }
    return (my_int_char(-1));
}

void mod_end(char c, char **end)
{
    if (c == '+')
        *end = "1";
    else
        self_op(end, "-1", mul_str);
}

char *my_getnbr_base(char const *str, char const *base)
{
    char *res = my_int_char(0);
    char *to_mul;
    char *to_add;
    int b_len = my_strlen(base);
    int s_len = my_strlen(str);
    int s_dex = 0;
    char *end = my_int_char(1);

    for (s_dex = s_len - 1; s_dex != -1; s_dex--){
        if (my_strcmp(get_index(base, str[s_dex]), "-1") != 0){
            to_mul = pow_str(my_int_char(b_len),
                my_int_char(s_len - s_dex - 1));
            to_add = mul_str(get_index(base, str[s_dex]), to_mul);
            self_op(&res, to_add, add_str);
        }else if (str[s_dex] == '+' || str[s_dex] == '-'){
            mod_end(str[s_dex], &end);
        }else
            return ("0");
    }
    return (self_op(&res, end, mul_str));
}
