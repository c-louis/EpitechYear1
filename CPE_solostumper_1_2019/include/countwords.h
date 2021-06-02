/*
** EPITECH PROJECT, 2020
** countwords
** File description:
** countwords header file
*/

typedef struct char_occur_s {
    int num;
    char *word;
    struct char_occur_s *next;
} char_oc_t;

char_oc_t *create_node(char *);
void add_node_end(char_oc_t **, char_oc_t *);
void free_nodes(char_oc_t *);
