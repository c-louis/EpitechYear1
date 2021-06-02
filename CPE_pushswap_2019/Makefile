##
## EPITECH PROJECT, 2019
## makefile for the pushswap
## File description:
## pushswap makefile
##

CFLAGS	=	-W -Wall -Wextra -I./include

LDFLAGS	=	-L./lib/ -lmy

SRC	=	main.c		\
		swap.c		\
		rotate.c	\
		rotatebis.c	\
		node_handling.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:
	$(MAKE) $(NAME)
	$(MAKE) -C ./lib/my

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my
	cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	rm $(OBJ)

fclean:
	find . -name ${NAME} -delete
	$(MAKE) clean -B
	$(MAKE) -C ./lib/my fclean -B

re:
	$(MAKE) fclean
	$(MAKE) all
