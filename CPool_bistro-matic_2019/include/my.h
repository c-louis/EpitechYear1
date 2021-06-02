/*
** EPITECH PROJECT, 2019
** my_header
** File description:
** Header for all libmy functions
*/

#ifndef _my_h
#define _my_h

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *);
int my_show_word_array(char * const *);

//backend functions

int abs_rec(int);
int my_is_prime_finder(int);
int is_recognized(char);
void swap_rev(char *, char *);
int get_display_length_mem(int, char const *);
int call_one_mem(int *, int *, char *, char const *);
int my_putnbr_base_mem(int, char const *, int);
int my_showmem_part(int *, char const *);
int get_display_length_show(int, char const *);
int call_one_show(int *, int *, char *, char const *);
int my_putnbr_base_show(int, char const *);
int my_isprintable(char);
void swap_sort(int *, int *);
int is_upcase(char);
int is_lowcase(char);
int get_len_strstr(char *);
int get_index_strstr(char *, char const *);
int is_alphanumeric(char);
int count_occur(char const *);
char **malloc_array(char const *);

#endif
