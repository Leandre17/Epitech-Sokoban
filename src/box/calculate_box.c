/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** calculate_box
*/

#include <stdbool.h>
#include <stdlib.h>
#include "soka.h"

bool is_wall(int x, int y, char **map)
{
    if (map[y][x] == '#' || map[y][x] == 'X' || map[y][x] == '@')
        return true;
    return false;
}

bool is_wall_despues(box_t *box, player_t *player)
{
    char **map = player->map->map;

    if (box == NULL)
        return false;
    if (is_wall(box->x, box->y - 1, map) && is_wall(box->x - 1, box->y, map))
        return true;
    if (is_wall(box->x, box->y + 1, map) && is_wall(box->x - 1, box->y, map))
        return true;
    if (is_wall(box->x, box->y - 1, map) && is_wall(box->x + 1, box->y, map))
        return true;
    if (is_wall(box->x, box->y + 1, map) && is_wall(box->x + 1, box->y, map))
        return true;
    return false;
}

player_t *can_be_moved(player_t *player)
{
    box_t *box = box_init(player);
    int count = 0;
    int count2 = 0;

    while (box != NULL) {
        count2 += is_wall_despues(box, player);
        count++;
        box = box->next;
    }
    if (count2 >= count)
        player->block = 1;
    else
        player->block = 0;
    return player;
}
