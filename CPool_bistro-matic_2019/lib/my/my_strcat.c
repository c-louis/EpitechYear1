/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char *src)
{
    int len = 0;

    for (; dest[len] != '\0'; len++);
    for (int i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    return (dest);
}
