/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Project
*/

#ifndef _inf_utils_h
#define _inf_utils_h

void my_memreset(char *, int);
int my_nbrlen(char *);
int my_compare(char *, char *);
int get_op(char *, char *);
char *neg_shift(char *);
char *get_starting_pointer(char *);
char *my_substring(char const *, int, int);
char *append_str(char *, char const *);

#define min(a, b)     ((a > b) ? (b) : (a))
#define max(a, b)     ((a > b) ? (a) : (b))
#define off(a)        ((a[0] == '-') ? (1) : (0))
#define sign(a, op)   ((op > 0) ? (1) : (a < 0) ? (-1) : (1))

#endif
