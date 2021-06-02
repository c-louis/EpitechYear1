/*
** EPITECH PROJECT, 2019
** eval header
** File description:
** header for the eval expr
*/

int is_basenumber(char *, char);
char get_base_operator(char *, char **);
int get_end_parenthesis(char *, int);
char *get_result(char *);
char *eval_expr(char const *);
char get_operator(char **);
void sanitalize_str(char *);
void replace_by_result(char *, int, int, char *);
int get_start_index(char *, int);
int get_end_index(char *, int);
void handle_parenthesis(char *);
void handle_factors(char *);
void handle_summands(char *);
char *my_strtol(char *, char **);
char *get_number(char *, int, char **, int);
char *factors(char **);
char *summands(char **);
