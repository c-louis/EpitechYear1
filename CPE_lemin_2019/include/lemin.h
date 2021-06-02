/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

typedef enum e_spec {
    BASIC,
    START,
    END
}spec_t;

typedef struct s_room
{
    int x;
    int y;
    int id;
    int busy;
    int visited;
    char *name;
    spec_t type;
    struct s_room **next;
} room_t;

typedef struct path
{
    room_t **path;
    struct path *next;
    struct path *prev;
} path_t;

typedef struct s_lemin
{
    room_t **anthill;
    int nb_ant;
}lemin_t;

// START FUNCTIONS

int start_lemin(void);
int get_info(lemin_t *lemin);
int fill_list(lemin_t *lemin);
int print_list(lemin_t *lemin);
int remove_comment(char *line);

// SOLVE FUNCTIONS

int solve(lemin_t *lemin);
int get_next_move(int pos, room_t **anthill);
path_t *append_path(path_t *path);
void remove_node(path_t *node, path_t **queue);

// ERROR FUNCTIONS

int start_error(lemin_t *lemin);
int check_ant(lemin_t *lemin);
int check_final(lemin_t *lemin);
int check_start(lemin_t *lemin);
int check_end(lemin_t *lemin);
int check_no_pipe(lemin_t *lemin);
int check_no_room(lemin_t *lemin);
int check_coord(lemin_t *lemin);

// IDENTIFIER FUNCTIONS

int is_pipe(char *line);
int is_room(char *line);
int is_command(char *line);
int is_comment(char *line);

// ROOM FUNCTIONS

char *get_name(char *line, int *len);
int get_x(char *line, int *len);
int get_y(char *line, int *len);

// PARSING FUNCTIONS

int add_room(char *info, lemin_t *lemin);
int add_pipe(char *info, lemin_t *lemin);

#endif /* !LEMIN_H_ */
