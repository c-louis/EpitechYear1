/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n carac of the string to another string
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    if (my_strlen(src) < n) {
        my_strcpy(dest, src);
        return (dest);
    }
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
