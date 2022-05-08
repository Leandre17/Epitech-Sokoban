/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** player
*/
#include <stdlib.h>
#include "my.h"
#include "soka.h"

player_t *reset_map(player_t *player)
{
    char *str = player->map->save;

    player->minx = 1;
    player->miny = 1;
    player->map->map = my_str_to_word_array(str);
    player->maxx = player->map->nb_cols - 1;
    player->maxy = player->map->nb_rows - 1;
    player = get_player_pos(player);
    player->map->filled = 0;
    player->block = 0;
    return player;
}

player_t *play_loop(player_t *player)
{
    switch (player->ch) {
        case KEY_LEFT:
            return move_player_left(player);
        case KEY_RIGHT:
            return move_player_right(player);
        case KEY_UP:
            return move_player_up(player);
        case KEY_DOWN:
            return move_player_down(player);
        case ' ':
            return reset_map(player);
    }
    return player;
}
