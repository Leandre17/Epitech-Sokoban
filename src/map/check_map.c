/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** check_map
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "soka.h"

int check_map(char const *filepath, char *map)
{
    int nb_box = 0;
    int nb_holes = 0;
    int perso = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        nb_box += is_box(map[i]);
        nb_holes += is_hole(map[i]);
        perso += is_player(map[i]);
        if (!is_good_char(map[i])) {
            free(map);
            return 84;
        }
    }
    free(map);
    if (perso != 1 || nb_holes != nb_box)
        return 84;
    return start(filepath);
}

int check_error(char const *filepath, char **env)
{
    int err = open(filepath, O_RDONLY);
    int size = 0;
    char *buffer = malloc(sizeof(char) * 10241024);

    if (err < 0 || env == NULL)
        return 84;
    size = read(err, buffer, 10241024);
    buffer[size] = '\0';
    if (is_in_env("TERM", env) == -1)
        return 84;
    return check_map(filepath, buffer);
}
