##
## EPITECH PROJECT, 2019
## sokoban
## File description:
## Makefile
##

SRC	=	src/main.c						\
		src/utils.c						\
		src/my_str_to_args.c			\
		src/shell_utils.c				\
		src/shell_path.c				\
		src/shell_env.c					\
		src/buildin/shell_buildin.c		\
		src/buildin/shell_cd.c			\
		src/buildin/shell_setenv.c		\
		src/buildin/shell_unsetenv.c	\
		src/commands/command_error.c	\
		src/commands/command_parse.c 	\
		src/commands/command_simple.c	\
		src/commands/command_checker.c		\
		src/commands/command_sanitalize.c	\
		src/commands/command.c				\
		src/commands/command_preprocess.c	\
		src/commands/command_redirect.c		\

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
