/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** start
*/
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "soka.h"

void init_win(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
}

void destroy_win(player_t *player)
{
    delwin(stdscr);
    endwin();
    free_tab(player->map->map);
    free(player->map);
    free(player);
}

int start(char const *filename)
{
    player_t * player = init_player(filename);
    int result = 0;

    init_win();
    player = game_loop(player);
    while (player->map->to_fill > player->map->filled && !player->block) {
        player->ch = getch();
        clear();
        player = game_loop(player);
        refresh();
    }
    if (player->map->to_fill > player->map->filled)
        result = 1;
    destroy_win(player);
    return result;
}
