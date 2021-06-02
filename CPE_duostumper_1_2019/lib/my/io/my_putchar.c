/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}