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
		src/menu/global_menu/menu.c \
		src/menu/files_menu/file_menu.c \
		src/menu/files_menu/open_menu.c \
		src/menu/global_menu/end_menu.c \
		src/menu/global_menu/quit_menu.c \
		src/menu/global_menu/start_menu.c \
		src/menu/edit_menu/edit/quit_edit.c \
		src/menu/files_menu/open_map_menu.c \
		src/menu/edit_menu/edit/edit_loop.c \
		src/menu/edit_menu/edit/edit_menu.c \
		src/menu/edit_menu/create/save_map.c \
		src/menu/edit_menu/create/create_new.c \
		src/menu/edit_menu/edit/edit_current.c \
		src/menu/edit_menu/edit/play_new_map.c \
		src/menu/edit_menu/create/create_map.c \
		src/menu/edit_menu/create/create_menu.c \

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

tests_run:
		make re -C tests
		./unit_tests
		gcovr

re: fclean all

.PHONY: clean $(NAME) all fclean
