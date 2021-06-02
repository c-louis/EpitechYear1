/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** launch_navy
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>

#include "navy.h"
#include "my.h"

extern global_t *NAVY;

int check_entry(char *entry)
{
    if (entry == NULL || my_strlen(entry) != 3) {
        return (1);
    } else if ((entry[0] < 'A' || entry[0] > 'H') ||
                (entry[1] < '1' || entry[1] > '8')) {
        my_printf("wrong position\n");
        return (1);
    }
    return (0);
}

int send_attack(char *attack)
{
    int x = 0;
    int y = 0;

    if (attack == NULL) {
        my_printf("OU EST LE DEBUG MATHIEU \n");
        return (1);
    }
    x = attack[0] - 65;
    y = attack[1] - 49;
    send_signal(x, y);
    return (0);
}

void attack_answer(char *attack)
{
    int x = attack[0] - 65;
    int y = attack[1] - 48 - 1;

    if (NAVY->coord->x == 8 && NAVY->coord->y == 8) {
        NAVY->enemyMap[y][x] = 'x';
        my_printf("%c%c: hit\n\n", attack[0], attack[1]);
    } else if (NAVY->coord->x == 9 && NAVY->coord->y == 9) {
        if (NAVY->enemyMap[y][x] != 'x')
            NAVY->enemyMap[y][x] = 'o';
        my_printf("%c%c: missed\n\n", attack[0], attack[1]);
    }
    NAVY->turn = 0;
}
