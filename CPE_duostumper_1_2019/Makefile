##
## EPITECH PROJECT, 2020
## STUMPER
## File description:
## Makefile
##

SRC	=	src/main.c 	\
		src/arg_handling.c \
		src/error.c	\
		src/errors.c	\
		src/tail.c	\
		src/file.c	\
		src/get_arg.c	\

CFLAGS = 	-L./lib/my -lmy -I./include

INCLUDE = 	-I./include -o

OBJ	=	$(SRC:.c=.o)

NAME =	tail

all:	$(NAME)

$(NAME): 	$(OBJ)
	make -C lib/my
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

valgrind:
	gcc $(SRC) -g $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)
