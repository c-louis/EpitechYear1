##
## EPITECH PROJECT, 2019
## do-op makefile
## File description:
## makefile for the doop thing
##

CFLAGS 	=	-I./include/ -W -Wall -Wextra

SRC 	=	infinite_add.c	\
		infinite_utils.c	\
		infinite_sub.c	\
		infinite_display_utils.c	\
		main.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	infin_add

all:
	$(MAKE) -C ./lib/my all
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra -I./include/ -L./lib -lmy

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all
