/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** reverse string
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int max = my_strlen(str);
    int i = 0;
    while (i < max/2)
    {
        char to_save = str[i];
        str[i] = str[max-1-i];
        str[max-1-i] = to_save;
        i++;
    }
    return (str);
}
