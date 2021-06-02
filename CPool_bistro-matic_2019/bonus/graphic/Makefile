##
## EPITECH PROJECT, 2019
## eval_expr
## File description:
## Makefile
##

SRC_BISTRO	=	../../operations/infinite_add.c		\
			../../operations/infinite_sub.c		\
			../../operations/infinite_mul.c		\
			../../operations/infinite_div.c		\
			../../operations/infinite_mod.c		\
			../../operations/infinite_pow.c		\
			../../utils/infinite_utils.c			\
			../../utils/infinite_number_utils.c		\
			../../convert_base/my_getnbr_base.c		\
			../../convert_base/my_int_to_char.c		\
			../../convert_base/convert_base.c		\
			../../convert_base/convert_utils.c		\
			../../eval_expr/eval_expr.c			\
			../../eval_expr/eval_utils.c			\
			../../eval_expr/handle_utils.c			\
			../../eval_expr/my_strtol.c			\
			../../eval_expr/operations.c			\
			../../eval_expr/sanitalize_str.c		\
			../../error/error_fun.c				\
			../../error/error_mes.c				\
			../../error/my_put_error.c			\
			../../error/error_utils.c			\

SRC	=	main.c			\
		squares.c		\
		framebuffer.c		\
		handler.c		\
		topbar.c		\
		event_dispatcher.c	\
		scroll_handler.c	\
		init.c			\
		cursor_utils.c		\
		text_handler.c		\


OBJ	=	$(SRC:.c=.o)
BOBJ 	=	$(SRC_BISTRO:.c=.o)

NAME	=	calculator

CFLAGS	=	-I../../include -L../../lib/my -lmy -l csfml-graphics -l csfml-window -g
LDFLAGS	=	-lcriterion -lgcov --coverage

all:
	$(MAKE) -C ../../lib/my --no-print-directory
	$(MAKE) -C ../../lib/my clean --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME):	$(OBJ) $(BOBJ)
	gcc -o $(NAME) $(OBJ) $(BOBJ) $(CFLAGS)

clean:
	rm -f $(BOBJ)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C ../../lib/my fclean

re:	fclean all
