##
## EPITECH PROJECT, 2019
## 105torus
## File description:
## Makefile
##

SRC	=	main.c		\
		calculation.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	105torus

CFLAGS	=	-I./include -lm

all:
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	$(MAKE) -C ./tests/
	./unit-tests

clean:
	rm -f $(OBJ)
##	$(MAKE) -C ./tests clean

fclean:	clean
	rm -f $(NAME)
	rm -f debug
##	$(MAKE) -C ./tests fclean

re:	fclean all

debug:
	$(MAKE) $(OBJ)
	gcc -o debug $(SRC) $(CFLAGS) -g
