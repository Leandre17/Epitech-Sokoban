/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** move_player
*/

#include "soka.h"

void move_player_left(player_t *player)
{
    switch (player->map->map[player->pos.y][player->pos.x - 1]) {
        case '#':
            return;
        case 'X':
            return move_box_left(player);
        case '@':
            return move_box_left(player);
        default:
            player->pos.x = new_pos(player->pos.x, player->min.x, true, -1);
    }
}

void move_player_up(player_t *player)
{
    switch (player->map->map[player->pos.y - 1][player->pos.x]) {
        case '#':
            return;
        case 'X':
            return move_box_up(player);
        case '@':
            return move_box_up(player);
        default:
            player->pos.y = new_pos(player->pos.y, player->min.y, true, -1);
    }
}

void move_player_down(player_t *player)
{
    switch (player->map->map[player->pos.y + 1][player->pos.x]) {
        case '#':
            return;
        case 'X':
            return move_box_down(player);
        case '@':
            return move_box_down(player);
        default:
            player->pos.y = new_pos(player->pos.y, player->max.y, false, 1);
    }
}

void move_player_right(player_t *player)
{
    switch (player->map->map[player->pos.y][player->pos.x + 1]) {
        case '#':
            return;
        case 'X':
            return move_box_right(player);
        case '@':
            return move_box_right(player);
        default:
            player->pos.x = new_pos(player->pos.x, player->max.x, false, 1);
    }
}
