/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** open_menu
*/

#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include "soka.h"
#include "my.h"

void my_menu_open_next(int chosen)
{
    if (chosen == 3)
        attron(A_REVERSE);
    mvprintw(LINES / 2 + 1, COLS / 2 - 4, "Custom    ");
    attroff(A_REVERSE);
    if (chosen == 4)
        attron(A_REVERSE);
    mvprintw(LINES / 2 + 2, COLS / 2 - 4, "Cancel    ");
    attroff(A_REVERSE);
}

void my_menu_open(int chosen)
{
    if (chosen == 0)
        attron(A_REVERSE);
    mvprintw(LINES / 2 - 2, COLS / 2 - 4, "easy      ");
    attroff(A_REVERSE);
    if (chosen == 1)
        attron(A_REVERSE);
    mvprintw(LINES / 2 - 1, COLS / 2 - 4, "Normal    ");
    attroff(A_REVERSE);
    if (chosen == 2)
        attron(A_REVERSE);
    mvprintw(LINES / 2, COLS / 2 - 4, "hard      ");
    attroff(A_REVERSE);
    my_menu_open_next(chosen);
}

void chosen_map(player_t *player)
{
    switch (player->menu.chosen) {
        case 0:
            return premaid_map(player, "maps/maptuto");
        case 1:
            return premaid_map(player, "maps/map");
        case 2:
            return premaid_map(player, "maps/mapcomplex");
        case 3:
            return new_map(player);
        case 4:
            return;
    }
}

void open_map(player_t *player)
{
    int chosen = player->menu.chosen;

    clear();
    mvprintw(LINES / 2 - 3, COLS / 2 - 4, "What open?");
    my_menu_open(player->menu.chosen);
    player->ch = getch();
    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen >= 4) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen <= 0) ? 4 : chosen - 1;
    else
        return chosen_map(player);
    return open_map(player);
}
