/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** player
*/
#include <stdlib.h>
#include "my.h"
#include "soka.h"

void reset_map(player_t *player)
{
    char *str = player->map->save;

    player->min.x = 1;
    player->min.y = 1;
    free_tab(player->map->map);
    player->map->map = my_str_to_word_array(str);
    player->max.x = player->map->nb_cols - 1;
    player->max.y = player->map->nb_rows - 1;
    get_player_pos(player);
    player->map->filled = 0;
    player->block = 0;
}


void play_loop(player_t *player)
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
}
