##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC 	=	my_putchar.c \
		my_putstr.c	\
		my_strlen.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: 		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)
	rm -f ../../libmy.a
