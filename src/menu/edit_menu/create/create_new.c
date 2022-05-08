/*
** EPITECH PROJECT, 2022
** mysokoban
** File description:
** create_new
*/

#include "my.h"
#include "soka.h"

void save_menu(player_t *player)
{
    char *menu[] = {"Save", "Play", "Save & play", "Cancel", "Quit", NULL};
    int chosen = player->menu.chosen;

    if (player->ch == KEY_DOWN)
        player->menu.chosen = (chosen == 4) ? 0 : chosen + 1;
    else if (player->ch == KEY_UP)
        player->menu.chosen = (chosen == 0) ? 4 : chosen - 1;
    for (int i = 0; i < 5; i++) {
        if (player->menu.chosen == i)
            attron(COLOR_PAIR(2));
        mvprintw(LINES / 2 + i, COLS / 2, menu[i]);
        attroff(COLOR_PAIR(2));
    }
}

void menu_save(player_t *player)
{
    void (*functions[])(player_t *) = {save_map, play_map, save_play, \
    cancel_choice, quit_edit, 0};

    clear();
    mvprintw(0, COLS / 2 - 12, "What do you want to do?");
    save_menu(player);
    player->ch = getch();
    if (player->ch != '\n')
        return menu_save(player);
    functions[player->menu.chosen](player);
}

void create_map_menu(player_t *player)
{
    curs_set(1);
    show_new_map(player);
    attron(COLOR_PAIR(1));
    while ((player->ch = getch()) != 'q' && player->ch != 's') {
        create_new_menu(player);
        show_new_map(player);
        move(player->menu.pos.y, player->menu.pos.x);
    }
    attroff(COLOR_PAIR(1));
    curs_set(0);
    menu_save(player);
    free_tab(player->menu.new_map);
}

void create_new_map(player_t *player)
{
    player->menu.new_map = mem_alloc_2d_array(20, 80);
    fill_new_map(player);
    create_map_menu(player);
}
