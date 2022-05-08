##
## EPITECH PROJECT, 2021
## B-CPE-110-BDX-1-1-BSQ-leandre.godet
## File description:
## Makefile
##
CFLAGS = -Wall -Wextra -Wshadow
CPPFLAGS = -I ./include

SRC = 	src/main.c \
		src/window/game.c \
		src/map/read_map.c \
		src/map/init_map.c \
		src/box/init_box.c \
		src/box/move_box.c \
		src/window/start.c \
		src/window/usage.c \
		src/map/bool_map.c \
		src/map/check_map.c \
		src/box/check_move.c \
		src/map/get_info_file.c \
		src/box/calculate_box.c \
		src/player/init_player.c \
		src/player/loop_player.c \
		src/player/move_player.c \

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

LIB = lib/my/libmy.a -lncurses

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my/
		make fclean -C tests

tests_run:
		make re -C tests
		./unit_tests
		gcovr

re: fclean all

.PHONY: clean $(NAME) all fclean
