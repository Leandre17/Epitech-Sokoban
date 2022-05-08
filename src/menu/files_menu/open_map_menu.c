/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** open_map_menu
*/

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include "soka.h"
#include "my.h"

int check_new_map(char const *filepath)
{
    int err = open(filepath, O_RDONLY);
    int size = 0;
    char *buffer = malloc(sizeof(char) * 10241024);

    if (err < 0)
        return 84;
    size = read(err, buffer, 10241024);
    buffer[size] = '\0';
    if (check_map(buffer) == 84)
        return 84;
    return 0;
}

char *my_get_str(char *msg)
{
    char *buffer = malloc(sizeof(char) * 320);
    int ch = 0;

    clear();
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(msg) / 2, msg);
    for (int index = 0;(ch = getch()) != '\n';) {
        if (ch == KEY_DC || ch == 127)
            index = (index > 0) ? index - 1 : 0;
        else {
            buffer[index] = ch;
            index++;
        }
        buffer[index] = '\0';
        clear();
        mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(msg) / 2, msg);
        mvprintw(LINES / 2, COLS / 2 - 10, buffer);
    }
    return buffer;
}

void new_map(player_t *player)
{
    char *filename = my_get_str("Enter a path to a map:");
    char *filename2 = my_strcat("maps/", filename);

    if (check_new_map(filename) == 84 && check_new_map(filename2) == 84) {
        clear();
        mvprintw(LINES / 2 - 3, COLS / 2 - 4, "Error");
        getch();
        return open_map(player);
    }
    free_tab(player->map->map);
    free(player->map);
    free(player);
    if (check_new_map(filename) == 84)
        player = init_player(filename2);
    else
        player = init_player(filename);
}

void premaid_map(player_t *player, char *filename)
{
    if (check_new_map(filename) == 84) {
        clear();
        mvprintw(LINES / 2 - 3, COLS / 2 - 4, "Error");
        getch();
        return open_map(player);
    }
    free_tab(player->map->map);
    free(player->map);
    free(player);
    player = init_player(filename);
    return;
}
