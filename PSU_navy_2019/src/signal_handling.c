/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** launch_navy
*/

// 9 - 8 Message Valid
// 8 - 9 Error message is not valid
// 8 - 8 Hit !
// 9 - 9 Missed !
// 0 - 0 Connected !

#include <unistd.h>
#include <signal.h>

#include "navy.h"
#include "my.h"

extern global_t *NAVY;

void handle_signal(void)
{
    if (NAVY->sig_c != 16)
        return;
    NAVY->sig_c = 0;
    NAVY->coord->x_s[4] = '\0';
    NAVY->coord->y_s[4] = '\0';
    NAVY->checksum[8] = '\0';
    NAVY->coord->x = to_dec(my_getnbr(NAVY->coord->x_s));
    NAVY->coord->y = to_dec(my_getnbr(NAVY->coord->y_s));
    if (to_dec(my_getnbr(NAVY->checksum)) != NAVY->coord->x + NAVY->coord->y) {
        send_signal(9, 8);
        NAVY->state = 2;
    } else
        NAVY->state = 3;
}

void send_num(char *nb, int size)
{
    int prec_o = 0;

    if (my_strlen(nb) < size)
        prec_o = size - my_strlen(nb);
    while (prec_o > 0) {
        kill(NAVY->enemy, SIGUSR2);
        usleep(1000);
        prec_o--;
    }
    while (prec_o < my_strlen(nb)) {
        if (nb[prec_o] == '0')
            kill(NAVY->enemy, SIGUSR2);
        else
            kill(NAVY->enemy, SIGUSR1);
        usleep(5000);
        prec_o++;
    }
}

void send_signal(int x, int y)
{
    char *x_s = to_bin(x);
    char *y_s = to_bin(y);
    char *check_s = to_bin(x + y);

    send_num(x_s, 4);
    send_num(y_s, 4);
    send_num(check_s, 8);
}

void handle_shoot(void)
{
    int x = NAVY->coord->x;
    int y = NAVY->coord->y;
    switch (NAVY->myMap[y][x]) {
    case '2': case '3': case '4': case '5':
        send_signal(8, 8);
        NAVY->myMap[y][x] = 'x';
        my_printf("%c%d: hit\n", x + 65, y+1);
        break;
    default:
        send_signal(9, 9);
        if (NAVY->myMap[y][x] != 'x')
            NAVY->myMap[y][x] = 'o';
        my_printf("%c%d: missed\n", x + 65, y+1);
        break;
    }
    NAVY->turn = 1;
}

void receive_signal(int sig, siginfo_t *info, void *ucontext)
{
    if (NAVY->enemy == -1)
        NAVY->enemy = info->si_pid;
    else if (NAVY->enemy != info->si_pid)
        return;
    if (NAVY->sig_c < 4) {
        NAVY->coord->x_s[NAVY->sig_c] = (sig == SIGUSR1) ? '1' : '0';
    }
    else if (NAVY->sig_c >= 4 && NAVY->sig_c < 8) {
        NAVY->coord->y_s[NAVY->sig_c - 4] = (sig == SIGUSR1) ? '1' : '0';
    }
    else {
        NAVY->checksum[NAVY->sig_c - 8] = (sig == SIGUSR1) ? '1' : '0';
    }
    NAVY->sig_c = NAVY->sig_c + 1;
}
