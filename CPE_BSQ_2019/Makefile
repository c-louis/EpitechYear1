##
## EPITECH PROJECT, 2019
## bsq
## File description:
## Makefile
##

SRC	=	bsq.c	\
		solution.c	\
		main.c	\
		error_handler.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-I./include -L./lib/my -lmy -g

all:
	make -C ./lib/my --no-print-directory
	make -C ./lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	$(MAKE) -C ./tests/
	./unit-tests

clean:
	rm -f $(OBJ)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a
##	$(MAKE) -C ./tests clean

fclean:	clean
	rm -f $(NAME)
	rm -f debug
##	$(MAKE) -C ./tests fclean

re:	fclean all

debug:
	make -C ./lib/my --no-print-directory
	make -C ./lib/my clean --no-print-directory
	$(MAKE) $(OBJ)
	gcc -o debug $(OBJ) $(CFLAGS) -g
