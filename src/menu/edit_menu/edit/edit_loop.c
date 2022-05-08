/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** edit_loop
*/

#include "soka.h"

void other_option(player_t *player)
{
    switch (player->ch) {
        case '0':
            player->menu.new_map[player->menu.pos.y][player->menu.pos.x] = ' ';
            break;
        case '1':
            player->menu.new_map[player->menu.pos.y][player->menu.pos.x] = 'O';
            break;
        case '2':
            player->menu.new_map[player->menu.pos.y][player->menu.pos.x] = 'X';
            break;
        case '3':
            player->menu.new_map[player->menu.pos.y][player->menu.pos.x] = 'P';
            break;
        case '4':
            player->menu.new_map[player->menu.pos.y][player->menu.pos.x] = '#';
    }
}

void create_new_menu(player_t *player)
{
    switch (player->ch) {
        case KEY_LEFT:
            player->menu.pos.x = new_pos(player->menu.pos.x, 0, true, -1);
            break;
        case KEY_RIGHT:
            player->menu.pos.x = new_pos(player->menu.pos.x, 79, 0, 1);
            break;
        case KEY_UP:
            player->menu.pos.y = new_pos(player->menu.pos.y, 0, true, -1);
            break;
        case KEY_DOWN:
            player->menu.pos.y = new_pos(player->menu.pos.y, 19, 0, 1);
            break;
    }
    other_option(player);
}
