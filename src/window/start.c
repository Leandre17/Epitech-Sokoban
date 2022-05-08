/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** start
*/
#include <stdlib.h>
#include "my.h"
#include "soka.h"

void init_win(void)
{
    initscr();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
}

void delete_win(player_t *player)
{
    endwin();
    delwin(player->win);
    free_tab(player->map->map);
    free(player->map);
    free(player);
}

int start(char const *filename)
{
    player_t *player = init_player(filename);

    while (1) {
        wclear(player->win);
        menu_menu(player);
        refresh();
        wrefresh(player->win);
        player->ch = getch();
    }
    delete_win(player);
    return 0;
}
