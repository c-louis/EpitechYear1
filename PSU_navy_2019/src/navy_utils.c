/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_utils
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "navy.h"

void my_wait(void)
{
    int waiting = 0;

    NAVY->state = 2;
    while (1) {
        usleep(1000000);
        waiting++;
        if (waiting == 100) {
            return;
        }
        if (NAVY->sig_c == 16) {
            NAVY->state = 3;
            return;
        }
    }
}

void get_signal(void)
{
    NAVY->state = 2;
    while (NAVY->state == 2) {
        my_wait();
        handle_signal();
    }
}

char *get_input(void)
{
    char *input = NULL;
    size_t len = 0;
    int read;

    while (check_entry(input)) {
        my_printf("attack: ");
        read = getline(&input, &len, stdin);
        if (read == -1) return (NULL);
    }
    return (input);
}