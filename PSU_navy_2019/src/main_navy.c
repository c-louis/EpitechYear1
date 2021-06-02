/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main_navy
*/

#include "my.h"
#include "navy.h"

void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("      ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("      first_player_pid:  only for the 2nd player.  pid of the");
    my_printf(" first player.\n");
    my_printf("      navy_positions:  file representing the positions of the");
    my_printf(" ships.\n");
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (!my_strcmp(av[1], "-h")) {
            print_usage();
            return (0);
        } else {
            return (p1_launch(av[1]));
        }
    } else if (ac == 3) {
        return (p2_launch(av[1], av[2]));
    } else {
        return (84);
    }
    return (0);
}