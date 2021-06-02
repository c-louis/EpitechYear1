/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copy n chars of str src into a str dest
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    int i;
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    for (i = 0; i < n && i < len; i++)
        dest[i] = str[i];
    if (n > len)
        dest[i] = '\0';
    return dest;
}
