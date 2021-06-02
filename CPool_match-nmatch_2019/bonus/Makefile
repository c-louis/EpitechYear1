##
## EPITECH PROJECT, 2019
## makefile for bonus 1
## File description:
## bonus
##

CFLAGS	=	-I./include/ -W -Wall -Wextra

SRC	=	explain_match_nmatch.c	\
		explication_match.c

OBJ	=	$(SRC:.c=.o)

NAME	=	match-nmatch

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -I./include/ -L./lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
