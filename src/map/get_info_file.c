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
#include "my.h"

int find_col(char **array)
{
    int col = 0;
    int old = 0;

    for (int i = 0; array[i] != NULL; i++) {
        col = my_strlen(array[i]);
        if (col >= old) {
            old = col;
        }
    }
    return old;
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
