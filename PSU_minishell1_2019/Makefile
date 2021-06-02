##
## EPITECH PROJECT, 2019
## sokoban
## File description:
## Makefile
##

SRC	=	main.c			\
		my_str_to_args.c	\
		shell_utils.c		\
		shell_path.c		\
		shell_env.c		\
		shell_command.c		\
		buildin/shell_buildin.c	\
		buildin/shell_cd.c	\
		buildin/shell_setenv.c	\
		buildin/shell_unsetenv.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./include -L./lib -lmy

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
	gcc -o debug $(SRC) $(CFLAGS) -g
