/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copy a str src into a str dest
*/

char *my_strcpy(char *dest, char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++){
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}
