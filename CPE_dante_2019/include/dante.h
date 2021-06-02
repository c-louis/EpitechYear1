/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_

// GENERATOR

typedef struct chain_s {
    long int id;
    int x_cell;
    int y_cell;
    struct chain_s *next;
    struct chain_s *prev;
}chain_t;

typedef struct list_s {
    chain_t *head;
    int length;
    int width_maze;
    int height_maze;
}list_t;

// SOLVER

typedef struct deadend_s {
    int x;
    int y;
} deadend_t;

typedef struct maze {
    int width;
    int height;
} maze_t;

int is_perfect(int ac, char **av);
int start_generator(int ac, char **av);
chain_t *get_random_wall(list_t *wall);
int prism_generator(char ** maze, int perfect, int width, int height);
int is_correct_wall(list_t *wall, char **maze, int x, int y);
int add_wall_to_list(list_t *wall, int x, int y);
int set_wall_from_cell(list_t *wall, char **maze, int x, int y);
int print_map(char **map);
int remove_wall(list_t *wall, int id, chain_t *delete);

// SOLVER

void free_array(char **);
void maze_exit(char **, int , char *);
void push_string(char ***, char *);
char **get_maze(char *);
void check_char(char, char **);

void fill_deadends(char **, maze_t *);
void fill_deadend(deadend_t *, char **);
int deadend_next(deadend_t *, char **, char);
deadend_t **get_deadend(char **, maze_t *);
int count_deadend(char **, maze_t *);

deadend_t *fill_result(char **maze, maze_t *maze_p);
int is_dend(int y, int x, char **maze, maze_t *maze_p);
int wall_count(int y, int x, char **maze);
char **copy_maze(char **maze);
void check_maze(char **maze);
int make_imperfect(char **maze, int width, int height);

#endif /* !DANTE_H_ */
