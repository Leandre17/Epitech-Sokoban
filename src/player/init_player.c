/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** init_player
*/

#include <stdlib.h>
#include "soka.h"

player_t *init_player(char const *filename)
{
    player_t *player = malloc(sizeof(player_t) + 1);

    player->minx = 1;
    player->miny = 1;
    player->ch = 'a';
    player->boxs = malloc(sizeof(box_t));
    player = map_init(filename, player);
    player->block = 0;
    return player;
}

int new_pos(int pos, int max, bool before, int speed)
{
    pos += speed;
    if (before && pos < max) {
        pos = max;
    } else if (!before && pos > max) {
        pos = max;
    }
    return pos;
}
