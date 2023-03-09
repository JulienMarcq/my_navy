##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

SRC = $(shell find -name '*.c')

OBJ = $(SRC:.c=.o);

NAMELIB = libmy.a

CFLAGS = -I./../../include/

all:	$(NAMELIB)

$(NAMELIB): $(SRC)
	@gcc -c $(SRC) $(CFLAGS) -Wall -Wextra
	@ar rc $(NAMELIB) $(OBJ)
	@make cleansilent

clean :
	rm -f $(OBJ)

cleansilent :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAMELIB)

re : fclean all
