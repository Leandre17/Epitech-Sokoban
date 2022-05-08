/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** init_box
*/

#include <stdlib.h>
#include "soka.h"

box_t *maillon(box_t *list, int x, int y)
{
    box_t *element = malloc(sizeof(box_t));

    if (element == NULL)
        return NULL;
    element->x = x;
    element->y = y;
    if (list == NULL)
        element->next = NULL;
    else
        element->next = list;
    return element;
}

box_t *find_all_box(char *str, int rows, box_t *box)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'X' || str[i] == '@') {
            box = maillon(box, i, rows);
        }
    }
    return box;
}

box_t *find_box(char **map, box_t *box)
{
    for (int i = 0; map[i] != NULL; i++) {
        box = find_all_box(map[i], i, box);
    }
    return box;
}

box_t *box_init(player_t *player)
{
    box_t *box = NULL;

    box = find_box(player->map->map, box);
    return box;
}
