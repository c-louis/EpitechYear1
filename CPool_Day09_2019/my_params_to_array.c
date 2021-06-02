/*
** EPITECH PROJECT, 2019
** my_params_to_array
** File description:
** convert array to struc info_param
*/

#include <stdlib.h>

char *my_strdup(char const *src);

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *dest;
    dest = malloc(sizeof(struct info_param) * ac + 1);
    while (i < ac) {
        int lengh = my_strlen(av[i]);
        char *copy;
        copy = malloc(sizeof(char) * lengh + 1);
        copy = my_strdup(av[i]);
        char *str = av[i];
        dest[i].word_array = my_str_to_word_array(str);
        dest[i].length = lengh;
        dest[i].str = str;
        dest[i].copy = copy;
        i++;
    }
    dest[i].str = "0";
    return (dest);
}
