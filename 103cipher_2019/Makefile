##
## EPITECH PROJECT, 2019
## 103cipher
## File description:
## Makefile
##

SRC	=	cipher.c		\
		matrix.c		\
		matrix_multiplication.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

CFLAGS	=	-I./include -lm

all:
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f debug

re:	fclean all

debug:
	$(MAKE) $(OBJ)
	gcc -o debug $(SRC) $(CFLAGS) -g
