/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** end.menu
*/

#include "soka.h"

void all_end_menu(player_t *player)
{
    char *menu[] = {"Retry            ", "Quit             ", "New              ", NULL};
    int chosen = player->menu.chosen;

    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen == 2) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen == 0) ? 2 : chosen - 1;
    for (int i = 0; i < 3; i++) {
        if (player->menu.chosen == i)
            attron(A_REVERSE);
        mvprintw(LINES / 2 + i, COLS / 2 - 9, menu[i]);
        attroff(A_REVERSE);
    }
}

void end_menu(player_t *player)
{
    void (*functions[])(player_t *) = {reset_map, quit_menu, open_map, 0};

    clear();
    mvprintw(LINES / 2 - 1, COLS / 2 - 9, "You reach the end");
    all_end_menu(player);
    player->ch = getch();
    if (player->ch != '\n')
        return end_menu(player);
    clear();
    functions[player->menu.chosen](player);
}