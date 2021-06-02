/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int lengh = my_strlen(str);
    int i = 0;
    while (i < lengh / 2) {
        char to_save = str[i];
        str[i] = str[lengh - i - 1];
        str[lengh - i - 1] = to_save;
        i++;
    }
    return (str);
}
