##
## EPITECH PROJECT, 2019
## 102architext
## File description:
## Makefile
##

SRC	=	archi.c		\
		matrix.c	\
		matrix_multiplication.c	\
		archi_movement.c	\
		checker.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

CFLAGS	=	-I./include -lm

all:
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:
	$(MAKE) $(OBJ)
	gcc -o debug $(OBJ) $(CFLAGS) -g
