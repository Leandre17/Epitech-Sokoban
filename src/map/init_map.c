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
#include "my.h"

player_t *get_player_posx(player_t *player, int row)
{
    int col = 0;
    while (col < (player->maxx + 1) && player->map->map[row][col] != '\0') {
        if (player->map->map[row][col] == 'P') {
            player->map->map[row][col] = ' ';
            player->posy = row;
            player->posx = col;
        }
        col += 1;
    }
    return player;
}

player_t *get_player_pos(player_t *player)
{
    int row = 0;

    while (row < (player->maxy + 1) && player->map->map[row] != NULL) {
        player = get_player_posx(player, row);
        row += 1;
    }
    return player;
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

player_t *map_init(char const *filename, player_t *player)
{
    map_t *map = malloc(sizeof(map_t));
    char *str = NULL;

    str = load_file_in_mem(filename);
    map->nb_rows = find_row(str);
    map->filled = 0;
    map->map = my_str_to_word_array(str);
    map->to_fill = find_all_complete(str);
    map->nb_cols = find_col(map->map);
    map->save = str;
    player->map = map;
    player->maxx = player->map->nb_cols - 1;
    player->maxy = player->map->nb_rows - 1;
    player = get_player_pos(player);
    return player;
}
