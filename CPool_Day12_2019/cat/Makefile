##
## EPITECH PROJECT, 2019
## do-op makefile
## File description:
## makefile for the doop thing
##

CFLAGS 	=	-I./../include/ -W -Wall -Wextra

SRC 	=	cat.c	\
		main.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra -I./../include/ -L./../lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

