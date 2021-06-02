/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** returns the number of characters in the str
*/

int my_strlen(char const *str)
{
    int counter = 0;
    for (; *str != '\0'; str++)
        counter++;
    return (counter);
}
