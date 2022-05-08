/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** check_move
*/

#include <stdbool.h>
#include "soka.h"

bool check_move(int x, int y, player_t *player)
{
    char current = player->map->map[y][x];

    if (current == '#' || current == 'X' || current == '@')
        return false;
    return true;
}

bool can_move(player_t *player, way_e way)
{
    switch (way) {
        case UP:
            return check_move(player->pos.x, player->pos.y - 2, player);
        case DOWN:
            return check_move(player->pos.x, player->pos.y + 2, player);
        case LEFT:
            return check_move(player->pos.x - 2, player->pos.y, player);
        case RIGHT:
            return check_move(player->pos.x + 2, player->pos.y, player);
    }
    return false;
}
