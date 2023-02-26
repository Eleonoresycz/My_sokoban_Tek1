##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra

CFLAGS += -I./include/ -Llib/my -lmy -g -lncurses

SRC	=	main.c \
		map.c \
		move.c \
		pos.c \
		end.c \
		tab_int.c \
		loop.c \
		switch.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make -C lib/my clean
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)
		make -C lib/my fclean

re:	fclean all