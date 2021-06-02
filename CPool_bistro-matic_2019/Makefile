##
## EPITECH PROJECT, 2019
## bistro-matic
## File description:
## Makefile
##

SRC	=	operations/infinite_add.c		\
		operations/infinite_sub.c		\
		operations/infinite_mul.c		\
		operations/infinite_div.c		\
		operations/infinite_mod.c		\
		operations/infinite_pow.c		\
		utils/infinite_utils.c			\
		utils/infinite_number_utils.c		\
		convert_base/my_getnbr_base.c		\
		convert_base/my_int_to_char.c		\
		convert_base/convert_base.c		\
		convert_base/convert_utils.c		\
		eval_expr/eval_expr.c			\
		eval_expr/eval_utils.c			\
		eval_expr/handle_utils.c		\
		eval_expr/my_strtol.c			\
		eval_expr/operations.c			\
		eval_expr/sanitalize_str.c		\
		error/error_fun.c			\
		error/error_mes.c			\
		error/my_put_error.c			\
		error/error_utils.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

CFLAGS	=	-I./include -L./lib/my -lmy

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
	$(MAKE) -C ./tests clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C ./tests fclean

re:	fclean all
