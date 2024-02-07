##
## EPITECH PROJECT, 2024
## Makefile libmy.a
## File description:
## create lib for my_printf
##

SRC = main.c \
	  ressources/player1.c \
	  ressources/player2.c \
	  ressources/connection.c \
	  ressources/map.c \
	  ressources/display.c \
	  ressources/bitshift.c \
	  ressources/signal.c \

OBJ = $(SRC:.c=.o)

CFLAGS += -Llib -lmy -Iinclude

NAME = navy

all: $(NAME)

required:
	make -C lib/my

$(NAME): required $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all
