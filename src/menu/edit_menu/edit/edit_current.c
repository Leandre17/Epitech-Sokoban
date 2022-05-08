/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** edit_current
*/

#include "soka.h"
#include "my.h"

char *strcatup(char *str, int len)
{
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    while (str[i] != '\0') {
        new[i] = str[i];
        i += 1;
    }
    while (i < len) {
        new[i] = ' ';
        i += 1;
    }
    new[i] = '\0';
    return new;
}

char **my_tabcpy(char **tab)
{
    char **new = malloc(sizeof(char *) * 20);
    int i = 0;

    while (i < 20 && tab[i] != NULL) {
        new[i] = strcatup(tab[i], 80);
        i++;
    }
    while (i < 20) {
        new[i] = strcatup(" ", 80);
        i++;
    }
    new[i] = NULL;
    return new;
}

void edit_current_map(player_t *player)
{
    reset_map(player);
    player->menu.new_map = my_tabcpy(player->map->map);
    player->menu.new_map[player->pos.y][player->pos.x] = 'P';
    create_map_menu(player);
    return;
}
