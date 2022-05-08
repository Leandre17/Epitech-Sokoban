/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** get_info_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "soka.h"

int find_col(char *str)
{
    int col = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        col += 1;
    }
    return col;
}

int find_row(char *str)
{
    int row = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            row += 1;
    }
    return row;
}
