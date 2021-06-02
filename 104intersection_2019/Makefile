##
## EPITECH PROJECT, 2019
## sokoban
## File description:
## Makefile
##

SRC	=	intersection.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	104intersection

CFLAGS	=	-I./include

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
	gcc -o debug $(SRC) $(CFLAGS) -g
