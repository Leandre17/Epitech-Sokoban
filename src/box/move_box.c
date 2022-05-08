/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** move_box
*/
#include "soka.h"

player_t *move_box_up(player_t *player)
{
    if (can_move(player, UP)) {
        if (player->map->map[player->posy - 2][player->posx] == 'O') {
            player->map->filled += 1;
            player->map->map[player->posy - 2][player->posx] = '@';
        } else
            player->map->map[player->posy - 2][player->posx] = 'X';
        player->posy = new_pos(player->posy, player->miny, true, -1);
        if (player->map->map[player->posy][player->posx] == '@') {
            player->map->map[player->posy][player->posx] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->posy][player->posx] = ' ';
    }
    return player;
}

player_t *move_box_down(player_t *player)
{
    if (player->map->map[player->posy + 2] == NULL)
        return player;
    if (can_move(player, DOWN)) {
        if (player->map->map[player->posy + 2][player->posx] == 'O') {
            player->map->map[player->posy + 2][player->posx] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->posy + 2][player->posx] = 'X';
        player->posy = new_pos(player->posy, player->maxy, false, 1);
        if (player->map->map[player->posy][player->posx] == '@') {
            player->map->map[player->posy][player->posx] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->posy][player->posx] = ' ';
    }
    return player;
}

player_t *move_box_right(player_t *player)
{
    if (can_move(player, RIGHT)) {
        if (player->map->map[player->posy][player->posx + 2] == 'O') {
            player->map->map[player->posy][player->posx + 2] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->posy][player->posx + 2] = 'X';
        player->posx = new_pos(player->posx, player->maxx, false, 1);
        if (player->map->map[player->posy][player->posx] == '@') {
            player->map->map[player->posy][player->posx] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->posy][player->posx] = ' ';
    }
    return player;
}

player_t *move_box_left(player_t *player)
{
    if (can_move(player, LEFT)) {
        if (player->map->map[player->posy][player->posx - 2] == 'O') {
            player->map->map[player->posy][player->posx - 2] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->posy][player->posx - 2] = 'X';
        player->posx = new_pos(player->posx, player->minx, true, -1);
        if (player->map->map[player->posy][player->posx] == '@') {
            player->map->map[player->posy][player->posx] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->posy][player->posx] = ' ';
    }
    return player;
}
