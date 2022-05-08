/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** game
*/

#include "soka.h"
#include "my.h"

void show_map(player_t *player)
{
    int map_len = 0;

    while (player->map->map[map_len] != NULL) {
        mvwprintw(player->win, map_len, 0, player->map->map[map_len]);
        map_len++;
    }
}

void game_loop(player_t *player)
{
    wattron(player->win, COLOR_PAIR(1));
    play_loop(player);
    show_map(player);
    mvwaddch(player->win, player->pos.y, player->pos.x, 'P');
    wattroff(player->win, COLOR_PAIR(1));
    can_be_moved(player);
    if (player->map->to_fill < player->map->filled || player->block)
        return end_menu(player);
}
