/*
** EPITECH PROJECT, 2020
** solostumper4 97 / 65
** File description:
** solostumper4 32 
*/

#include <unistd.h>

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Usage: USNameFormatter string\n", 30);
        return (84);
    }
    char **name = my_str_to_word_array(av[1]);
    if (my_strlen(name[0]) > 2 && my_strcapitalize(name[0]));
    else if (my_strlen(name[0]) <= 2 && my_strupcase(name[0]));
    if (name[2] != NULL && my_strcapitalize(name[2])) {
        if (name[1][0] >= 97 && name [1][0] == (name[1][0] -= 32));
    } else
        my_strcapitalize(name[1]);
    my_printf("%s ", name[0]);
    if (name[2] != NULL && my_printf("%c. %s\n", name[1][0], name[2]));
    else
        my_printf("%s\n", name[1]);
}
