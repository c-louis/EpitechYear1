/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** project
*/

#ifndef PROJECT_H_
#define PROJECT_H_

typedef struct {
    int x;
    int y;
    int width;
    int height;
} t_params;

int count_nearby(int **table, t_params params);

void check_top_left(int *count, int **table, t_params params);
void check_top_right(int *count, int **table, t_params params);
void check_bottom_left(int *count, int **table, t_params params);
void check_bottom_right(int *count, int **table, t_params params);

int **gameoflife(int **table, t_params params);

// Function of checker.c
int is_map_okay(char **map);

// Function of game.c
int start_game(char **, int);

#endif /* !PROJECT_H_ */
