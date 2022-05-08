/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** read_map
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "soka.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **result = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    result[nb_rows] = NULL;
    return result;
}

char *load_file_in_mem(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 320000);
    int fd = open(filepath, O_RDONLY);
    int size = read(fd, buffer, 320000);

    if (fd < 0)
        return NULL;
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

char **load_2d_arr_from_file(char const *str, int nb_rows, int nb_cols)
{
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);
    int l = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            map[i][j] = str[l];
            l += 1;
        }
        map[i][nb_cols] = '\0';
        l += 1;
    }
    map[nb_rows] = NULL;
    return map;
}
