/*
** EPITECH PROJECT, 2019
** header pushswap
** File description:
** blablabla
*/

typedef struct nb_list {
    int nb;
    struct nb_list *next;
    struct nb_list *prev;
} lnb_t;

typedef struct container {
    lnb_t *head;
    lnb_t *tail;
    int size;
    char buffer[4096];
    int buff_index;
} cont_t;

void ra(cont_t *l_a);
void rra(cont_t *l_a);
void sa(cont_t *l_a);
lnb_t *create_node(char *cnb);
void add_node_end(cont_t *cont, lnb_t *node);
