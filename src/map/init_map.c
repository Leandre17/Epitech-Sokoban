/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** init_map
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "soka.h"

void get_player_posx(player_t *player, int row)
{
    int col = 0;
    while (col < player->max.x) {
        if (player->map->map[row][col] == 'P') {
            player->map->map[row][col] = ' ';
            player->pos.y = row;
            player->pos.x = col;
        }
        col += 1;
    }
}

void get_player_pos(player_t *player)
{
    int row = 0;

    while (row < player->max.y) {
        get_player_posx(player, row);
        row += 1;
    }
}

int find_all_complete(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'O') {
            count++;
        }
    }
    return count;
}

void map_init(char const *filename, player_t *player)
{
    map_t *map = malloc(sizeof(map_t));
    char *str = load_file_in_mem(filename);

    map->nb_rows = find_row(str);
    map->nb_cols = find_col(str);
    map->filled = 0;
    map->map = load_2d_arr_from_file(str, map->nb_rows, map->nb_cols);
    map->to_fill = find_all_complete(str);
    map->save = str;
    player->map = map;
    player->max.x = player->map->nb_cols - 2;
    player->max.y = player->map->nb_rows - 2;
    get_player_pos(player);
}
