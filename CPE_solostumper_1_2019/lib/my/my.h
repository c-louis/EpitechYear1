/*
** EPITECH PROJECT, 2019
** libmy header
** File description:
** header for the libmy library
*/

#include <stdarg.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_is_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const **);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int n);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char * const);
int my_str_isnum(char * const);
int my_str_islower(char * const);
int my_str_isupper(char * const);
int my_str_isprintable(char * const);
int my_showstr(char * const);
int my_showmem(char * const, int);
char *my_strcat(char *, char * const);
char *my_strncat(char *, char * const, int);
int my_show_word_array(char ** const);
char **my_str_to_word_array(char * const);
int my_is_even(int);
void display_all(int, int);
int determine_nb_size(int);
int ten_power(int);
void to_lowercase(char *, int);
void to_uppercase(char *, int);
int is_separator(char);
int is_letter(char);
int check_next_caracter(char *, char * const, int);
int new_start(int, char * const);
void copy_word(char *, int, int, char * const);
int is_alphanumeric(char);
char *my_strdup(char const *);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_find_prime_sup(int);
int check_limit(char const *, char *, int);
int isForbid(char const *, int, int);
int get_number(char const *, int);
int my_putnbr_base(int nbr, char const *base);
int my_printf(char *str, ...);

/* prntf function */
int pr_str(va_list ap);
int pr_int(va_list ap);
int pr_char(va_list ap);
int pr_bin(va_list ap);
int pr_allstr(va_list ap);
int pr_uint(va_list ap);
int pr_hexa(va_list ap);
int pr_oct(va_list ap);
int pr_percent(va_list ap);
int pr_pointer(va_list ap);
int determine_uint_size(unsigned int nb);
void display_all_uint(int nb_size, unsigned int nb);
int my_put_uint(unsigned int nb);
