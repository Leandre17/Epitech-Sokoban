/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** edit_menu
*/

#include <ncurses.h>
#include "soka.h"
#include "my.h"

void sub_menu_edit(player_t *player)
{
    char *menu[] = {"Edit", "Create", "Lorel", "Ipsum", NULL};
    int chosen = player->menu.chosen;

    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen == 3) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen == 0) ? 3 : chosen - 1;
    for (int i = 0; i < 4; i++) {
        if (player->menu.chosen == i)
            attron(COLOR_PAIR(2));
        mvprintw(i + 1, 5, menu[i]);
        attroff(COLOR_PAIR(2));
    }
}

void all_edit_menu(player_t *player)
{
    void (*functions[])(player_t *) = {edit_current_map, create_menu, 0, 0, 0};
    int chosen = player->menu.chosen;

    mvprintw(0, 0, "File");
    attron(A_REVERSE);
    mvprintw(0, 5, "Edit");
    sub_menu_edit(player);
    attroff(A_REVERSE);
    if (player->ch != '\n')
        return;
    player->menu.type = play;
    player->menu.chosen = 0;
    functions[chosen](player);
    return menu_menu(player);
}

void print_menu_edit(player_t *player)
{
    if (player->menu.type != 1) {
        player->menu.type = edit;
        return all_edit_menu(player);
    } else {
        player->ch = 0;
        return menu_display(player);
    }
}