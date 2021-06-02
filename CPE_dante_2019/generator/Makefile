##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME_GEN	=	generator

SRC_GEN		=	src/main_generator.c 		\
				src/start_gen.c 			\
				src/prism_utils.c 			\
				src/prism_generator.c 		\
				src/prism_cell.c 			\
				src/make_imperfect.c		\

OBJ_GEN     =   $(SRC_GEN:.c=.o)

CFLAGS  =	-Wall -Wextra -I./../include -L../lib -l my -Ofast

all:    $(NAME_GEN)

$(NAME_GEN):	$(OBJ_GEN)
	make -C ../lib/
	gcc -o $(NAME_GEN) $(OBJ_GEN) $(CFLAGS)

clean:
	make -C ../lib/ clean
	rm -f $(OBJ_GEN)

fclean: clean
	rm -f $(NAME_GEN)

re:     fclean all
