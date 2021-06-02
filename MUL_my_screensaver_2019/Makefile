##
## EPITECH PROJECT, 2019
## makefile for the screen save
## File description:
## screen saver makefile
##

CFLAGS	=	-W -Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

SRC	=	main.c		\
		framebuffer.c	\
		anim/line.c	\
		anim/circle.c	\
		utils/line.c	\
		init.c		\
		event_handler.c	\
		printer.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

all:
	$(MAKE)	-C lib/my
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm $(OBJ)
	$(MAKE) -C lib/my/ clean


fclean:
	find . -name ${NAME} -delete
	$(MAKE) -C lib/my/ fclean -B
	$(MAKE) clean -B

re:
	$(MAKE) fclean
	$(MAKE) all
