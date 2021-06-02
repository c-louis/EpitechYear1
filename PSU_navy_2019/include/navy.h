/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>

typedef struct coords {
    int x;
    int y;
    char x_s[5];
    char y_s[5];
} coord_t;

typedef struct s_global {
    int sig_c;
    coord_t *coord;
    char checksum[8];
    int state;
    int me;
    int enemy;
    int **myMap;
    int **enemyMap;
    int turn;
} global_t;

global_t *NAVY;

// Initialization function
int init_global(char *, char *);

// Launching function according to the player
int p1_launch(char *map_file);
int p2_launch(char *pid_player, char *map_file);
int game_loop(void);

// Map getting function
char **open_file(char *path_file);
int **convert_map(char **map);
int verify_map(char **data_map);
int verify_diag_boat(char *data_line);
int put_boat_on_map(char **data_map, int **map);
int is_letter_coord(char c);
int convert_letter_on_map(char **data_map);
int **load_blank_map(void);
int **get_map(char *);

// Map printing function
void print_map(int **map);
void print_maps(void);

// Signal traductor / converter
char *to_bin(int nb);
int to_dec(int nb);

// Signal functions

void my_wait(void);
void get_signal(void);
char *get_input(void);

// Signal handling
void receive_signal(int sig, siginfo_t *info, void *ucontext);
void handle_signal(void);
void send_num(char *, int);
void send_signal(int, int);

// Gameplay function
void handle_shoot(void);

// Attack handling
int check_entry(char *);
int send_attack(char *attack);
void attack_answer(char *attack);

#endif /* !NAVY_H_ */