##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main_navy.c 			\
				src/launch_navy.c 			\
				src/map_handling/open_map.c		\
				src/map_handling/convert_map.c 		\
				src/map_handling/verify_map.c 		\
				src/map_handling/convert_letter.c 	\
				src/map_handling/fill_map.c 		\
				src/map_handling/print_map.c		\
				src/convert_base.c 			\
				src/signal_handling.c			\
				src/init.c				\
				src/attack.c				\
				src/game.c				\
				src/navy_utils.c        \
				src/map_handling/verify_diag_boat.c

OBJ     =       $(SRC:.c=.o)

NAME	=	navy

NAME_TEST	=	unit_test

CFLAGS  =	-Wall -Wextra -I./include -Llib -l my

LDFLAGS =       -lcriterion -lgcov --coverage -I./include -Llib -l my

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run : fclean $(OBJ)
	make -C lib/
	gcc -o $(NAME_TEST) $(SRC) $(LDFLAGS)
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
	rm -f $(OBJ)
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	make -C lib/
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all
