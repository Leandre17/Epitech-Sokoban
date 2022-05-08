/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leandre.godet
** File description:
** start_menu
*/

#include <stdlib.h>
#include <ncurses.h>
#include "soka.h"
#include "my.h"


void my_menu_start_next(int chosen)
{
    if (chosen == 3)
        attron(A_REVERSE);
    mvprintw(LINES / 2 + 1, COLS / 2 - 4, "Custom");
    attroff(A_REVERSE);
    if (chosen == 4)
        attron(A_REVERSE);
    mvprintw(LINES / 2 + 2, COLS / 2 - 4, "Quit");
    attroff(A_REVERSE);
}

void my_menu_start(int chosen)
{
    if (chosen == 0)
        attron(A_REVERSE);
    mvprintw(LINES / 2 - 2, COLS / 2 - 4, "easy");
    attroff(A_REVERSE);
    if (chosen == 1)
        attron(A_REVERSE);
    mvprintw(LINES / 2 - 1, COLS / 2 - 4, "Normal");
    attroff(A_REVERSE);
    if (chosen == 2)
        attron(A_REVERSE);
    mvprintw(LINES / 2, COLS / 2 - 4, "hard");
    attroff(A_REVERSE);
    my_menu_start_next(chosen);
}

char const *start_custom_map(void)
{
    char *filename = my_get_str("Enter a path to a custom map");
    char *filename2 = my_strcat("maps/", filename);

    if (check_new_map(filename) == 84 && check_new_map(filename2) == 84) {
        clear();
        mvprintw(LINES / 2 - 3, COLS / 2 - 4, "Error");
        getch();
        return NULL;
    } else if (check_new_map(filename) == 84)
        return filename2;
    return filename;
}

int custom_map_start(char const *filename)
{
    if (filename == NULL || check_new_map(filename))
        return 1;
    start(filename);
    return 'q';
}

int start_new_map(int chosen)
{
    endwin();
    switch (chosen) {
        case 0:
            return custom_map_start("maps/maptuto");
        case 1:
            return custom_map_start("maps/map");
        case 2:
            return custom_map_start("maps/mapcomplex");
        case 3:
            return custom_map_start(start_custom_map());
        case 4:
            return 'q';
    }
    return chosen;
}

int start_menu(int chosen)
{
    int ch = 0;

    while (ch != 'q') {
        clear();
        mvprintw(LINES / 2 - 3, COLS / 2 - 10, "Welcome to the game!");
        my_menu_start(chosen);
        ch = getch();
        if (ch == KEY_DOWN)
            chosen = (chosen >= 4) ? 0 : chosen + 1;
        else if (ch == KEY_UP)
            chosen = (chosen <= 0) ? 4 : chosen - 1;
        else
            ch = start_new_map(chosen);
    }
    return 0;
}
