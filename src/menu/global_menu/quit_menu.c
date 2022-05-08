/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** quit_menu
*/

#include <ncurses.h>
#include "soka.h"
#include "my.h"

void my_menu_quit(player_t *player)
{
    if (player->menu.chosen == 0)
        attron(A_REVERSE);
    mvprintw(LINES / 2, COLS / 2 - 1, "Yes");
    attroff(A_REVERSE);
    if (player->menu.chosen == 1)
        attron(A_REVERSE);
    mvprintw(LINES / 2 + 1, COLS / 2 - 1, "No");
    attroff(A_REVERSE);
}

void anser_player(player_t *player)
{
    if (player->menu.chosen == 0) {
        delete_win(player);
        exit(0);
    }
}

void quit_menu(player_t *player)
{
    int chosen = (player->menu.chosen > 1) ? 1 : player->menu.chosen;

    clear();
    player->menu.chosen = chosen;
    mvprintw(LINES / 2 - 1, COLS / 2 - 16, "Are you sure you want to quit?");
    my_menu_quit(player);
    player->ch = getch();
    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen >= 1) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen <= 0) ? 1 : chosen - 1;
    else
        return anser_player(player);
    return quit_menu(player);
}
