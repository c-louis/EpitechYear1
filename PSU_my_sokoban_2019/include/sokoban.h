/*
** EPITECH PROJECT, 2019
** sokoban struct and func
** File description:
** func and struc
*/

typedef struct solution {
    int x;
    int y;
} solution_t;

typedef struct gsoko {
    int row;
    int column;
    char *smap;
    char **map;
    solution_t **soluce;
    int state;
} gsoko_t;

char **make_map(char *, gsoko_t *);
char *read_map(char *);
int get_mapcolumn(char *);
int get_maprow(gsoko_t *);
int get_playerline(gsoko_t *);
int get_playercolumn(gsoko_t *);
void move_down(gsoko_t *);
void move_up(gsoko_t *);
void move_left(gsoko_t *);
void move_right(gsoko_t *);
void init_solution(gsoko_t *);
void init_soko(gsoko_t *, int, char **);
void set_ncurses_param(void);
void draw_map(gsoko_t *);
void reset(gsoko_t *);
void handle_movement(gsoko_t *, int);
void handle_solution(gsoko_t *);
void handle_defeat(gsoko_t *);
void game_loop(gsoko_t *);
int check_map(gsoko_t *);
int main_soko(int, char **);
int check_basic_error(int, char **);
void print_help(void);
