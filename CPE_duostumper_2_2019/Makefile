##
## EPITECH PROJECT, 2020
## STUMPER
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/count_nearby.c		\
		src/checker.c			\
		src/check_diagonals.c		\
		src/game.c			\
		src/gameoflife.c		\

CFLAGS =	-I./include

INCLUDE = 	-I./include -o

OBJ	=	$(SRC:.c=.o)

NAME =	gameoflife

all:	$(NAME)

$(NAME): 	$(OBJ)
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests:
	sh tests/gameoflife.sh

.PHONY: all clean fclean re tests

valgrind:
	gcc $(SRC) -g $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)
