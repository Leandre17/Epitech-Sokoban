/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** save_map
*/

#include <fcntl.h>
#include <unistd.h>
#include "soka.h"
#include "my.h"

void put_array_in(char **array, int fd)
{
    for (int i = 0; array[i] != NULL; i++) {
        write(fd, array[i], my_strlen(array[i]));
        write(fd, "\n", 1);
    }
}

void save_map(player_t *player)
{
    char *filename = my_get_str("Entrer le nom de la map voulu");
    int fd = 0;

    filename = my_strcat("maps/", filename);
    fd = open(filename, O_RDONLY);
    if (fd >= 0) {
        clear();
        mvprintw(LINES / 2 - 3, COLS / 2 - 4, "Error");
        getch();
        return save_map(player);
    }
    fd = open(filename, O_CREAT | O_WRONLY, 0666);
    put_array_in(player->menu.new_map, fd);
    close(fd);
}