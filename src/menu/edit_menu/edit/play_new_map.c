/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** play_new_map
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "soka.h"

int return_count(int argc, char **argv)
{
    int j = 0;
    int count = argc;

    while (j != argc) {
        count = count + my_strlen(argv[j]);
        j = j + 1;
    }
    return (count);
}

char *concat_map(char **map)
{
    int count = return_count(len_array(map), map);
    int i = 0;
    int k = 0;
    int l = 0;
    char *dest = malloc(sizeof(char) * count + 1);

    while (count > k && l < len_array(map)) {
        dest[k] = map[l][i];
        if (map[l][i] == '\0') {
            dest[k] = '\n';
            i = 0;
            l = l + 1;
        } else
            i += 1;
        k += 1;
    }
    dest[k] = '\0';
    return dest;
}

void play_map(player_t *player)
{
    free(player->map->save);
    player->map->save = concat_map(player->menu.new_map);
    player->map->nb_rows = find_row(player->map->save);
    player->map->nb_cols = find_col(player->map->save);
    player->map->filled = 0;
    player->map->to_fill = find_all_complete(player->map->save);
    player->max.x = player->map->nb_cols - 2;
    player->max.y = player->map->nb_rows - 2;
    player->block = 0;
    player->win = newwin(player->map->nb_rows, player->map->nb_cols, 1, \
    COLS / 2 - player->map->nb_cols / 2);
    reset_map(player);
    return;
}

void save_play(player_t *player)
{
    save_map(player);
    play_map(player);
    return;
}
