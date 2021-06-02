##
## EPITECH PROJECT, 2019
## lucas.decrock@epitech.eu
## File description:
## Libmy's Makefile
##

SRC	=	checks/is_alphanum.c \
		checks/is_different.c \
		checks/is_lower.c \
		checks/is_negative.c \
		checks/is_numeric.c \
		checks/is_prime.c \
		checks/is_printable.c \
		checks/is_upper.c \
		io/my_printf/my_printf_types_basic.c \
		io/my_printf/my_printf_types_complex.c \
		io/my_printf/my_put_uint.c \
		io/my_printf/my_printf.c \
		io/my_putchar.c \
		io/my_puterr.c \
		io/my_putnbr.c \
		io/my_putstr.c \
		numbers/convert_base.c \
		numbers/my_getnbr.c \
		strings/lcfirst.c \
		strings/my_strlen.c \
		strings/strrev.c \
		strings/strtolower.c \
		strings/strtoupper.c \
		strings/ucfirst.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME): 	$(OBJ)
	rm ../../include/my.h
	cp my.h ../../include
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re