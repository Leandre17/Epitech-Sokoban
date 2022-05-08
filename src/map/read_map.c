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

char *load_file_in_mem(char const *filepath)
{
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    int size = 0;

    buffer = malloc(sizeof(char) * 320000);
    size = read(fd, buffer, 320000);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
