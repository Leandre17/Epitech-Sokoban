/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** bool_map
*/

#include <stdbool.h>
#include "soka.h"

bool is_player(char ch)
{
    if (ch == 'P')
        return true;
    return false;
}

bool is_box(char ch)
{
    if (ch == 'X')
        return true;
    return false;
}

bool is_hole(char ch)
{
    if (ch == 'O')
        return true;
    return false;
}

bool is_good_char(char ch)
{
    if (ch == 'O' || ch == 'X' || ch == 'P')
        return true;
    else if (ch == '#' || ch == '\n' || ch == ' ')
        return true;
    return false;
}
