/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** create_map
*/

#include "soka.h"

void fill_map(player_t *player, int y)
{
    int x = 0;
    while (x < 80) {
        player->menu.new_map[y][x] = ' ';
        x++;
    }
    player->menu.new_map[y][x] = '\0';
}

void fill_new_map(player_t *player)
{
    for (int i = 0; player->menu.new_map[i] != NULL; i++) {
        fill_map(player, i);
    }
}

void show_new_map(player_t *player)
{
    int map_len = 0;

    clear();
    while (player->menu.new_map[map_len] != NULL) {
        mvprintw(map_len, 0, player->menu.new_map[map_len]);
        map_len++;
    }
}
