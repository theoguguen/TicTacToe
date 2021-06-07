##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRCDIR	=	src/

SRC		=	$(SRCDIR)printer.c	\
			$(SRCDIR)get_input.c	\
			$(SRCDIR)check_win.c	\
			$(SRCDIR)check_draw.c	\
			$(SRCDIR)counter.c	\
			$(SRCDIR)main.c	\
			$(SRCDIR)atoi.c	\
			$(SRCDIR)init_array.c	\

NAME		=	tictactoe

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-I include -Wall -Wextra -W

all:	$(NAME)


$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@rm -fr $(OBJ)

fclean:	clean
	@rm -fr $(NAME)

re:	fclean all

debug:	CFLAGS += -g
debug:	re
