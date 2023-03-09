##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

OBJ = $(SRC:.c=.o);

sor = src/

sor_func = src/functions/

sor_error = src/errors/

sor_players = src/players/

SRC =  	$(shell ls $(sor)*.c) \
		$(shell ls $(sor_func)*.c) \
		$(shell ls $(sor_error)*.c) \
		$(shell ls $(sor_players)*.c)

NAME = navy

LIB = -L ./lib/my/ -lmy

CC = gcc

CFLAGS = -I./include/ -Wall -Wextra -g

all: $(NAME)

$(NAME): $(SRC)
	@make -C lib/my/ -s
	gcc $(SRC) -o $(NAME) $(LIB) $(CFLAGS)

clean :
	@rm -f $(OBJ)
	@make clean -C lib/my/ -s

cleannolib :
	@rm -f $(OBJ)

fclean : cleannolib
	@rm -f $(NAME)
	@make fclean -C lib/my/ -s

re : fclean all
