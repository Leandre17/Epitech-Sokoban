/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** game
*/

#include "soka.h"
#include "my.h"

void show_str(char *str, int len)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@')
            mvprintw(len, i, "X");
        else
            mvprintw(len, i, "%c", str[i]);
    }
}

void show_map(player_t *player)
{
    int map_len = 0;

    while (player->map->map[map_len] != NULL) {
        show_str(player->map->map[map_len], map_len);
        map_len++;
    }
}

player_t *game_loop(player_t *player)
{
    int taille = my_strlen(Terminal_low);

    if (LINES < player->map->nb_rows || COLS < player->map->nb_cols)
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), Terminal_low);
    else {
        player = play_loop(player);
        show_map(player);
        mvaddch(player->posy, player->posx, 'P');
    }
    return can_be_moved(player);
}
