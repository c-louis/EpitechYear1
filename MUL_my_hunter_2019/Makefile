##
## EPITECH PROJECT, 2019
## my_hunter
## File description:
## Makefile
##

CFLAGS	=	-W -Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my -lmy -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

SRC	=	main.c				\
		events/event_dispatcher.c	\
		events/event_handler.c		\
		events/pigeon_death.c		\
		events/event_click.c		\
		lists/pigeon_list_utils.c	\
		lists/dead_pigeon_list_utils.c	\
		anim/alive_pigeon_anim.c	\
		anim/dead_pigeon_anim.c		\
		init/init.c			\
		init/init_second.c		\
		init/init_menu.c		\
		init/init_menu_button.c		\
		init/init_expli.c		\
		init/init_credit.c		\
		init/init_expli_sprite.c	\
		clean/clean.c			\
		clean/clean_list.c		\
		utils/score.c			\
		utils/loop.c			\
		utils/menu_loop.c		\
		utils/ammo.c			\
		utils/my_int_to_char.c		\
		utils/utility.c			\
		sound_handler.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:
	$(MAKE) -C lib/my
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm $(OBJ)
	find . -name "*.o" -delete
	$(MAKE) -C lib/my/ clean -B

fclean:
	find . -name ${NAME} -delete
	$(MAKE) -C lib/my/ fclean -B
	$(MAKE) clean -B

re:
	$(MAKE) all
	$(MAKE) fclean
	$(MAKE) all
