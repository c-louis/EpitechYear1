/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** Split a string into words
*/

#include <stdlib.h>

int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int count_occur(char const *src)
{
    int counter = 0;
    int prev = -1;

    for (int i = 0; src[i] != '\0'; i++){
        if (is_alphanumeric(src[i]) == 0 && prev == 0){
            counter++;
            prev = -1;
        }else if (is_alphanumeric(src[i]) == 1){
            prev = 0;
        }
    }
    return (counter);
}

char **malloc_array(char const *src)
{
    int len = count_occur(src) + 2;
    char **res = malloc(sizeof(char *) * len);
    int i = 0;
    int i_res = 0;

    for (int j = 0; j == 0 || src[j - 1] != '\0'; j++){
        if (is_alphanumeric(src[j]) == 0 && i_res != 0){
            res[i] = malloc(sizeof(char) * (i_res + 1));
            i_res = 0;
            i++;
        }else if (is_alphanumeric(src[j]) == 1){
            i_res++;
        }
    }
    res[i] = malloc(sizeof(char));
    return (res);
}

char **my_str_to_word_array(char const *src)
{
    char **res = malloc_array(src);
    int i = 0;
    int i_res = 0;

    for (int j = 0; j == 0 || src[j - 1] != '\0'; j++){
        if (is_alphanumeric(src[j]) == 0 && i_res != 0){
            res[i][i_res] = '\0';
            i++;
            i_res = 0;
        }else if (is_alphanumeric(src[j]) == 1){
            res[i][i_res] = src[j];
            i_res++;
        }
    }
    res[i] = 0;
    return (res);
}
