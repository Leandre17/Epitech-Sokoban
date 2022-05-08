/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** file_menu
*/

#include <ncurses.h>
#include "soka.h"
#include "my.h"

int change_to_right(int ch, int chosen)
{
    switch (ch) {
        case 'o':
            return 0;
        case 'r':
            return 1;
        case 'q':
            return 2;
    }
    return chosen;
}

void sub_menu_file(player_t *player)
{
    char *menu[] = {"Open", "Rset", "Quit", NULL};
    int chosen = player->menu.chosen;

    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen == 2) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen == 0) ? 2 : chosen - 1;
    else
        player->menu.chosen = change_to_right(player->ch, chosen);
    for (int i = 0; i < 3; i++) {
        if (player->menu.chosen == i)
            attron(COLOR_PAIR(2));
        mvprintw(i + 1, 0, menu[i]);
        attroff(COLOR_PAIR(2));
    }
}

void all_file_menu(player_t *player)
{
    void (*functions[])(player_t *) = {open_map, reset_map, quit_menu, 0};

    attron(A_REVERSE);
    sub_menu_file(player);
    mvprintw(0, 0, "File");
    attroff(A_REVERSE);
    mvprintw(0, 5, "Edit");
    if (player->ch != '\n')
        return;
    player->menu.type = play;
    functions[player->menu.chosen](player);
    return menu_menu(player);
}

void print_menu_file(player_t *player)
{
    if (player->menu.type != 2) {
        player->menu.type = 2;
        return all_file_menu(player);
    } else {
        player->ch = 0;
        return menu_display(player);
    }
}
