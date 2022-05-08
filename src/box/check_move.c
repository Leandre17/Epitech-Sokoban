/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** check_move
*/

#include <stdbool.h>
#include "soka.h"

bool check_move(int posx, int posy, player_t *player)
{
    char current = 0;
    char **map = player->map->map;

    if (map == NULL || map[posy] == NULL)
        return false;
    else if (player->maxy <= posy || posy <= 0 || player->maxx < posx)
        return false;
    current = player->map->map[posy][posx];
    if (current == '#' || current == 'X' || current == '@')
        return false;
    return true;
}

bool can_move(player_t *player, way_e way)
{
    switch (way) {
        case UP:
            return check_move(player->posx, player->posy - 2, player);
        case DOWN:
            return check_move(player->posx, player->posy + 2, player);
        case LEFT:
            return check_move(player->posx - 2, player->posy, player);
        case RIGHT:
            return check_move(player->posx + 2, player->posy, player);
    }
    return false;
}
