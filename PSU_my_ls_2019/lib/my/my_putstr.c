/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** put str display string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = my_strlen(str);
    write(1, str, i);
    return (0);
}
