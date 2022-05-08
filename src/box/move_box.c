/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** move_box
*/
#include "soka.h"

void move_box_up(player_t *player)
{
    if (can_move(player, UP)) {
        if (player->map->map[player->pos.y - 2][player->pos.x] == 'O') {
            player->map->filled += 1;
            player->map->map[player->pos.y - 2][player->pos.x] = '@';
        } else
            player->map->map[player->pos.y - 2][player->pos.x] = 'X';
        player->pos.y = new_pos(player->pos.y, player->min.y, true, -1);
        if (player->map->map[player->pos.y][player->pos.x] == '@') {
            player->map->map[player->pos.y][player->pos.x] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->pos.y][player->pos.x] = ' ';
    }
}

void move_box_down(player_t *player)
{
    if (can_move(player, DOWN)) {
        if (player->map->map[player->pos.y + 2][player->pos.x] == 'O') {
            player->map->map[player->pos.y + 2][player->pos.x] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->pos.y + 2][player->pos.x] = 'X';
        player->pos.y = new_pos(player->pos.y, player->max.y, false, 1);
        if (player->map->map[player->pos.y][player->pos.x] == '@') {
            player->map->map[player->pos.y][player->pos.x] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->pos.y][player->pos.x] = ' ';
    }
}

void move_box_right(player_t *player)
{
    if (can_move(player, RIGHT)) {
        if (player->map->map[player->pos.y][player->pos.x + 2] == 'O') {
            player->map->map[player->pos.y][player->pos.x + 2] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->pos.y][player->pos.x + 2] = 'X';
        player->pos.x = new_pos(player->pos.x, player->max.x, false, 1);
        if (player->map->map[player->pos.y][player->pos.x] == '@') {
            player->map->map[player->pos.y][player->pos.x] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->pos.y][player->pos.x] = ' ';
    }
}

void  move_box_left(player_t *player)
{
    if (can_move(player, LEFT)) {
        if (player->map->map[player->pos.y][player->pos.x - 2] == 'O') {
            player->map->map[player->pos.y][player->pos.x - 2] = '@';
            player->map->filled += 1;
        } else
            player->map->map[player->pos.y][player->pos.x - 2] = 'X';
        player->pos.x = new_pos(player->pos.x, player->min.x, true, -1);
        if (player->map->map[player->pos.y][player->pos.x] == '@') {
            player->map->map[player->pos.y][player->pos.x] = 'O';
            player->map->filled -= 1;
        } else
            player->map->map[player->pos.y][player->pos.x] = ' ';
    }
}
