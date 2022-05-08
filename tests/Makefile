##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	test_ncur.c \
		../src/map/bool_map.c \
		../src/map/init_map.c \
		../src/map/read_map.c \
		../src/map/check_map.c \
		../src/map/get_info_file.c \
		../src/player/init_player.c \
		../src/player/loop_player.c \
		../src/player/move_player.c \
		../src/box/calculate_box.c \
		../src/box/check_move.c \
		../src/box/init_box.c \
		../src/box/move_box.c \

NAME =	unit_tests

OBJ = $(SRC.c=.o)

CFLAGS = -I ../include
CPPFLAGS = --coverage -lcriterion
LIB = ../lib/my/libmy.a

all:	$(NAME)
$(NAME): $(OBJ)
	make -C ../lib/my/
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LIB)
	cp unit_tests ../

clean:
	rm -f $(NAME)
	rm -f ../$(NAME)

fclean:	clean
	rm -f *~
	rm -f *.gc*

re:	fclean all

.PHONY: all clean fclean re
