/*
** EPITECH PROJECT, 2022
** lib
** File description:
** check_env
*/

#include <stddef.h>
#include "my.h"

int is_in_str(char *str, char *to_check)
{
    int len_to_check = my_strlen(to_check);
    int i = 0;

    while (i < len_to_check) {
        if (to_check[i] != str[i]) {
            return 0;
        }
        i += 1;
    }
    if (str[i] == '=')
        return 1;
    return 0;
}

int is_in_env(char *name, char **env)
{
    int i = 0;

    if (name == NULL || env == NULL)
        return -2;
    while (env[i] != NULL) {
        if (is_in_str(env[i], name)) {
            return i;
        }
        i += 1;
    }
    return -1;
}
