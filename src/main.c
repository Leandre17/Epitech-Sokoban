/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include "soka.h"
#include "my.h"

int main(int argc, char **argv, char **env)
{
    if (argc != 2)
        return 84;
    else if (argv[1][0] == '-' && argv[1][1] == 'h')
        return usage();
    return check_error(argv[1], env);
}
