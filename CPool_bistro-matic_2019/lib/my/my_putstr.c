/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display a string given as parameter
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (; *str != '\0'; str++)
        my_putchar(*str);
    return (0);
}
