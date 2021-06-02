/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** error includes
*/

#ifndef _error_h
#define _error_h

void sign_follow(char *op, char *sign, char *num, int size);
void check_base(char const *b);
void check_ops(char const *ops);
void my_put_error(char *str);
void argc_nb(int ac);
int malloc_test(char *str);
int size_check(char *operation, int size);
int op_check(char *op, char *num, char *sign, int size);
int error(int ac, char *operation, char **av, int size);
int find_num(char op, char *num);
int check_par(char *op, char *opbase, int size);
void base_check(char *num, char *sign);
int is_operator_base(char c, char *opbase);
#endif
