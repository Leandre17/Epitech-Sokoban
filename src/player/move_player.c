/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** move_player
*/

#include "soka.h"

player_t *move_player_left(player_t *player)
{
    switch (player->map->map[player->posy][player->posx - 1]) {
        case '#':
            return player;
        case 'X':
            return move_box_left(player);
        case '@':
            return move_box_left(player);
        default:
            player->posx = new_pos(player->posx, player->minx, true, - 1);
    }
    return player;
}

player_t *move_player_up(player_t *player)
{
    switch (player->map->map[player->posy - 1][player->posx]) {
        case '#':
            return player;
        case 'X':
            return move_box_up(player);
        case '@':
            return move_box_up(player);
        default:
            player->posy = new_pos(player->posy, player->miny, true, - 1);
    }
    return player;
}

player_t *move_player_down(player_t *player)
{
    if (!player->map->map[player->posy + 1])
        return player;
    switch (player->map->map[player->posy + 1][player->posx]) {
        case '#':
            return player;
        case 'X':
            return move_box_down(player);
        case '@':
            return move_box_down(player);
        default:
            player->posy = new_pos(player->posy, player->maxy, false, 1);
    }
    return player;
}

player_t *move_player_right(player_t *player)
{
    switch (player->map->map[player->posy][player->posx + 1]) {
        case '#':
            return player;
        case 'X':
            return move_box_right(player);
        case '@':
            return move_box_right(player);
        default:
            player->posx = new_pos(player->posx, player->maxx, false, 1);
    }
    return player;
}
