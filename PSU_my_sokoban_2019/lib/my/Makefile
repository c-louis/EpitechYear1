##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for libmy
##

SRC	=	my_is_prime.c		\
		my_show_word_array.c	\
		my_str_isalpha.c	\
		my_strncat.c		\
		my_putchar.c		\
		my_sort_int_array.c	\
		my_str_islower.c	\
		my_strncmp.c		\
		my_compute_power_rec.c	\
		my_put_nbr.c		\
		my_strcapitalize.c	\
		my_str_isnum.c		\
		my_strncpy.c		\
		my_compute_square_root.c	\
		my_putstr.c		\
		my_strcat.c		\
		my_str_isprintable.c	\
		my_strstr.c		\
		my_find_prime_sup.c	\
		my_revstr.c		\
		my_strcmp.c		\
		my_str_isupper.c	\
		my_str_to_word_array.c	\
		my_getnbr.c		\
		my_showmem.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_strupcase.c		\
		my_isneg.c		\
		my_showstr.c		\
		my_strdup.c		\
		my_strlowcase.c		\
		my_swap.c		\
		my_putnbr_base.c	\
		my_printf.c		\
		print_utils.c		\
		print_utils2.c		\
		my_put_uint.c		\

OBJ 	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
