##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME_SOLV	=	solver

SRC_SOLV	=	src/main_solver.c	\
				src/maze.c			\
				src/deadend.c		\
				src/solver.c		\

OBJ_SOLV	=	$(SRC_SOLV:.c=.o)

CFLAGS  =	-Wall -Wextra -I./../include -L../lib -l my -Ofast

all:    $(NAME_SOLV)

$(NAME_SOLV):	$(OBJ_SOLV)
	make -C ../lib/
	gcc -o $(NAME_SOLV) $(OBJ_SOLV) $(CFLAGS)

clean:
	rm -f $(OBJ_SOLV)

fclean: clean
	rm -f $(NAME_SOLV)

re:     fclean all
