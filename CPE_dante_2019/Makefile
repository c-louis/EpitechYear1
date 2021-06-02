##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME    =   dante

all:    $(NAME)

$(NAME):
	make -C solver/
	make -C generator/

clean:
	make -C solver/ clean
	make -C generator/ clean
	make -C lib/ clean
	find . -type f \(  -name "*~" -o -name "#*#" \) -delete
	find . -type f \( -name "*.gcno" -o -name "*.gcda" \) -delete

valgrind: fclean
	clear
	make -C lib/
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

fclean: clean
	make -C solver/ fclean
	make -C generator/ fclean
	rm -f $(NAME_TEST)
	make -C lib/ fclean

re:     fclean all
