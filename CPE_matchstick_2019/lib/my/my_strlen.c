/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** lengh of the string
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i = i + 1;
    }
    return (i);
}
