/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game handling
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

void check_wins(void)
{
    int total_boat_p1 = 0;
    int total_boat_p2 = 0;

    for (int i = 0; i < 8 ; i++) {
        for (int j = 0; j < 8 ; j++) {
            total_boat_p1 += (NAVY->myMap[i][j] == 'x') ? 1 : 0;
            total_boat_p2 += (NAVY->enemyMap[i][j] == 'x') ? 1 : 0;
        }
    }
    if (total_boat_p2 == 14) {
        print_maps();
        my_printf("I won\n");
        NAVY->state = 0;
    } else if (total_boat_p1 == 14) {
        print_maps();
        my_printf("Enemy won\n");
        NAVY->state = 0;
    }
}

void handle_connection(void)
{
    my_printf("my_pid: %d\n", NAVY->me);
    if (NAVY->enemy == -1) {
        my_printf("waiting for enemy connection...\n");
        while (NAVY->state == 1 || NAVY->state == 2) {
            my_wait();
            handle_signal();
        }
        my_printf("enemy connected\n\n");
        send_signal(0, 0);
    } else {
        send_signal(0, 0);
        while (NAVY->state == 1 || NAVY->state == 2) {
            my_wait();
            handle_signal();
        }
        my_printf("successfully connected\n\n");
    }
}

void loop1(void)
{
    char *attack;

    if (NAVY->state == 0) {
        return;
    }
    attack = get_input();
    send_attack(attack);
    NAVY->state = 2;
    get_signal();
    attack_answer(attack);
    my_printf("waiting for enemy's attack...\n");
    get_signal();
    handle_shoot();
}

void loop2(void)
{
    char *attack;

    my_printf("waiting for enemy's attack...\n");
    get_signal();
    handle_shoot();
    attack = get_input();
    if (send_attack(attack) == 1) {
        NAVY->state = 0;
        return;
    }
    get_signal();
    attack_answer(attack);
}

int game_loop(void)
{
    if (NAVY->state == 1) {
        handle_connection();
        return (1);
    }
    print_maps();
    if (NAVY->turn == 0) {
        loop2();
    } else {
        loop1();
    }
    check_wins();
    return (NAVY->state);
}
