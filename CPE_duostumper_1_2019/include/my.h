/*
** EPITECH PROJECT, 2020
** lucas.decrock@epitech.eu
** File description:
** Libmy's include file
*/

/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| LIB MY by lucas.decrock@epitech.eu
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|
| Collection of essentials functions used in all C projects.
|
| Last updated at : 11/02/2020
| Last updated in : CPE_matchstick_2019
|
*/

#ifndef MY_H_
#define MY_H_

/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Type Checks (is_numeric, is_lower, ...)
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

int	is_alphanum(char const c);
int is_alphanum_str(char const *str);

int is_different(char const *str1, char const *str2);

int	is_lower(char const c);
int is_lower_str(char const *str);

int is_negative(int const n);

int	is_numeric(char const c);
int is_numeric_str(char const *str);

int is_prime(int const nb);

int	is_printable(char const c);
int is_printable_str(char const *str);

int	is_upper(char const c);
int is_upper_str(char const *str);

/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Input / Ouput (my_printf, my_putstr, my_getfile, ..)
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

int my_printf(char const *str, ...);

void my_putchar(char const c);

void my_puterr(char const *error);

int my_putnbr(int nb);
int my_putnbr_unsigned(unsigned int nb);

void my_putstr(char const *str);

/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Numbers manipulation (convert_base, my_getnbr, ...)
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

char *convert_base(int nb, int base);

int my_getnbr(char const *str);

/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Strings manipulation (strrev, strtoupper, lcfirst, ...)
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

char *lcfirst(char *str);

int my_strlen(char const *str);

char *strrev(char *str);

char *strtolower(char *str);

char *strtoupper(char *str);

char *ucfirst(char *str);


#endif /* !MY_H_ */