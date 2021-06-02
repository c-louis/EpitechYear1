##
## EPITECH PROJECT, 2019
## test_file_bistro
## File description:
## Makefile
##

SRC	=	../operations/infinite_add.c		\
		../operations/infinite_sub.c		\
		../operations/infinite_mul.c		\
		../operations/infinite_div.c		\
		../operations/infinite_mod.c		\
		../operations/infinite_pow.c		\
		../utils/infinite_utils.c		\
		../utils/infinite_number_utils.c	\
		../convert_base/convert_base.c		\
		../convert_base/convert_utils.c		\
		../convert_base/my_int_to_char.c	\
		../convert_base/my_getnbr_base.c	\
		../eval_expr/eval_expr.c		\
		../eval_expr/eval_utils.c		\
		../eval_expr/handle_utils.c		\
		../eval_expr/my_strtol.c		\
		../eval_expr/operations.c		\
		../eval_expr/sanitalize_str.c		\
		../error/my_put_error.c			\
		../error/error_fun.c			\
		../error/error_mes.c			\
		../error/error_utils.c			\
		test_bistro.c				\
		test_error.c				\
		test_convert.c				\
		test_eval_expr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	unit-tests

CFLAGS	=	-I./../include -L./../lib/my -lmy --coverage -lcriterion

all:
	make -C ./../lib/my --no-print-directory
	make -C ./../lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	cp $(NAME) ../$(NAME)

clean:
	rm -f $(OBJ)
	find .. -name "*.gcno" -delete -o -name "*.gcda" -delete

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
