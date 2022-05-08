/*
** EPITECH PROJECT, 2021
** tncs
** File description:
** usage.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

int usage(void)
{
    int fd = open("src/window/usage", O_RDONLY);
    char buf[241];
    int size;

    if (fd < 0)
        return 84;
    size = read(fd, buf, 241);
    write(1, buf, size);
    close(fd);
    return 0;
}
