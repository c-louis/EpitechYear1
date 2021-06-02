/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concat two string with nb limit of char
*/

int my_strlen(char const *src);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int src_lengh = my_strlen(src);
    int dest_lengh = my_strlen(dest);
    if (nb > src_lengh)
        nb = src_lengh;
    while (i < nb) {
        dest[dest_lengh + i] = src[i];
        i++;
    }
    dest[dest_lengh + nb] = '\0';
    return (dest);
}
