/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Concatenates n chars of src into dest
*/

char *my_strncat(char *dest, char *src, int nb)
{
    int len = 0;
    int i = 0;

    for (; dest[len] != '\0'; len++);
    for (; src[i] != '\0' && i < nb; i++)
        dest[len + i] = src[i];
    if (i == nb)
        dest[len + i] = '\0';
    return (dest);
}
