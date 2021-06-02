/*
** EPITECH PROJECT, 2020
** STUMPER
** File description:
** project
*/

#ifndef PROJECT_H_
#define PROJECT_H_

struct options {
    int bytes;
    int lines;
    int quiet;
    int start;
    int ret;
};

void add_path(char ***str, char *av);

// file.c function
int get_file_size(char *);
int get_line_count(char *);
char **get_parsed(char *);
char **parse_text(char *);
char *read_file(char *);

// tail.c function
int tail(struct options *opt, char **);

// error.c function
int print_err_open(char *, struct options *opt);
void print_verbose(char *, struct options *opt);

// errors.c
void err_invalidarg(char *str, struct options *opt);

// arg_handling
int is_arg(char *str, struct options *opt);
int handle_arg_bool(struct options *opt, char **av, int i);
int handle_arg_num(struct options *opt, char **av, int i);

#endif /* !PROJECT_H_ */
