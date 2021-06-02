##
## EPITECH PROJECT, 2019
## sokoban
## File description:
## Makefile
##

SRC	=	main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	USNameFormatter

CFLAGS	=	-I./include -L./lib/my -lmy

all:
	make -C ./lib/my --no-print-directory
	make -C ./lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a

fclean:	clean
	rm -f $(NAME)
	rm -f debug

re:	fclean all

debug:
	make -C ./lib/my --no-print-directory
	make -C ./lib/my clean --no-print-directory
	$(MAKE) $(OBJ)
	gcc -o debug $(SRC) $(CFLAGS) -g
