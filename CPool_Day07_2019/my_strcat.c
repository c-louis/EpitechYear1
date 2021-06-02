/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concat two string
*/

int my_strlen(char const *src);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int src_lengh = my_strlen(src);
    int dest_lengh = my_strlen(dest);

    while (i < src_lengh) {
        dest[dest_lengh + i ] = src[i];
        i++;
    }
    return (dest);
}
