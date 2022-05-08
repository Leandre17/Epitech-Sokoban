/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** menu
*/

#include <ncurses.h>
#include "soka.h"
#include "my.h"

void menu_display(player_t *player)
{
    switch (player->ch) {
        case 'e':
            return print_menu_edit(player);
        case 'f':
            return print_menu_file(player);
        default:
            mvprintw(0, 5, "Edit");
            mvprintw(0, 0, "File");
            player->menu.type = 0;
            return game_loop(player);
    }
}

void menu_menu(player_t *player)
{
    clear();
    show_map(player);
    mvwaddch(player->win, player->pos.y, player->pos.x, 'P');
    if (player->menu.type == play || player->ch == 'f' || player->ch == 'e') {
        player->menu.chosen = 0;
        menu_display(player);
    }
    switch (player->menu.type) {
        case edit:
            return all_edit_menu(player);
        case file:
            return all_file_menu(player);
    }
}
