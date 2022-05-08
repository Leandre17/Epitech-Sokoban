/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** create_menu
*/

#include "soka.h"

void all_create_menu(player_t *player)
{
    char *menu[] = {"New", "Edit", "Quit", NULL};
    int chosen = player->menu.chosen;

    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen == 2) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen == 0) ? 2 : chosen - 1;
    for (int i = 0; i < 3; i++) {
        if (player->menu.chosen == i)
            attron(A_REVERSE);
        mvprintw(LINES / 2 + i, COLS / 2 - 2, menu[i]);
        attroff(A_REVERSE);
    }
}

void create_menu(player_t *player)
{
    int chosen = player->menu.chosen;
    void (*functions[])(player_t *) = {create_new_map, edit_current_map, \
    quit_menu, 0};

    clear();
    mvprintw(LINES / 2 - 1, COLS / 2 - 16, "What do you want to do create?");
    all_create_menu(player);
    player->ch = getch();
    if (player->ch != '\n')
        return create_menu(player);
    player->menu.chosen = 0;
    functions[chosen](player);
}
