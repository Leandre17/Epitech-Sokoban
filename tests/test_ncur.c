/*
** EPITECH PROJECT, 2021
** test_projet
** File description:
** test_projet
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include "soka.h"
#include "my.h"

int start(char const *filename)
{
    return 0;
}

bool is_wall_despues(box_t *box, player_t *player);

Test(sokaban, test_projet)
{
    box_t *box = malloc(sizeof(box_t));
    box_t *box2 = malloc(sizeof(box_t));
    box_t *box3 = malloc(sizeof(box_t));
    box_t *box_null = NULL;
    player_t *player = init_player("maps/map");

    box->x = 1;
    box->y = 1;
    box2->x = 2;
    box2->y = 2;
    box3->x = 7;
    box3->y = 9;
    my_putchar(player->map->map[box3->y][box3->x]);
    cr_assert_eq(is_wall_despues(box, player), true);
    cr_assert_eq(is_wall_despues(box2, player), false);
    cr_assert_eq(is_wall_despues(box3, player), true);
    cr_assert_eq(is_wall_despues(box_null, player), false);
    cr_assert_eq(can_move(player, UP), FALSE);
    cr_assert_eq(can_move(player, DOWN), FALSE);
    cr_assert_eq(can_move(player, RIGHT), true);
    cr_assert_eq(can_move(player, LEFT), true);
    cr_assert_eq(can_move(player, 55), false);
    can_be_moved(player);
    move_box_up(player);
    move_box_down(player);
    move_box_left(player);
    move_box_right(player);
    player->posy += 1;
    move_box_up(player);
    move_box_down(player);
    player->posy += 1;
    move_box_left(player);
    move_box_right(player);
    reset_map(player);
    player->ch = 404;
    play_loop(player);
    player->ch = 405;
    play_loop(player);
    player->ch = 403;
    play_loop(player);
    player->ch = 402;
    play_loop(player);
    player->ch = 4;
    play_loop(player);

    player = move_player_right(player);
    player = move_player_right(player);
    player = move_player_right(player);
    player = move_player_right(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_right(player);
    player = move_player_up(player);
    player = move_player_right(player);
    player = move_player_down(player);
    player = move_player_right(player);
    player = move_player_right(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_up(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_down(player);
    player = move_player_left(player);
    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_left(player);
    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_right(player);
    player = move_player_right(player);

    free(box);
    free(box2);
    free(box3);
    free_tab(player->map->map);
    free(player->map);
    free(player);
}

Test(sokaban, test_player)
{
    player_t *player = init_player("maps/tests/test1");

    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_right(player);
    player = move_player_up(player);
    player = move_player_left(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    free_tab(player->map->map);
    free(player->map);
    free(player);

    player = init_player("maps/tests/test2");

    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_down(player);
    player = move_player_left(player);
    player = move_player_down(player);
    player = move_player_right(player);
    player->ch = KEY_LEFT;
    player = play_loop(player);
    player->ch = KEY_RIGHT;
    player = play_loop(player);
    player->ch = KEY_UP;
    player = play_loop(player);
    player->ch = KEY_DOWN;
    player = play_loop(player);
    player->ch = ' ';
    player = play_loop(player);
    player = move_player_up(player);
    free_tab(player->map->map);
    player->map->map = NULL;
    check_move(0, 0, player);
    free(player->map);
    free(player);

    player = init_player("maps/tests/test5");

    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_down(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_left(player);
    player = move_player_up(player);
    player = move_player_right(player);
    player = move_player_down(player);
    player = move_player_right(player);
    player = move_player_up(player);
    player = move_player_right(player);
    player = move_player_up(player);
    player = move_player_up(player);
    player = move_player_left(player);
    player = move_player_down(player);
    player = move_player_down(player);

    free_tab(player->map->map);
    free(player->map);
    free(player);
}

Test(sokaban, bool_map)
{
    int err = open("maps/tests/test1", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 10241024);
    int size = read(err, buffer, 10241024);
    int err2 = open("maps/tests/test3", O_RDONLY);
    char *buffer2 = malloc(sizeof(char) * 10241024);
    int size2 = read(err2, buffer2, 10241024);
    int err3 = open("maps/tests/test4", O_RDONLY);
    char *buffer3 = malloc(sizeof(char) * 10241024);
    int size3 = read(err3, buffer3, 10241024);
    char **env2 = NULL;
    char **env1 = malloc(sizeof(char *) * 2);
    char **env0 = malloc(sizeof(char *) * 2);

    env1[0] = "TERM=color";
    env1[1] = NULL;
    env0[0] = "PATH=/usr";
    env0[1] = NULL;
    buffer[size] = '\0';
    buffer2[size2] = '\0';
    buffer3[size3] = '\0';
    cr_assert_eq(is_player('P'), true);
    cr_assert_eq(is_player('d'), false);
    cr_assert_eq(is_box('P'), false);
    cr_assert_eq(is_box('X'), true);
    cr_assert_eq(is_hole('P'), false);
    cr_assert_eq(is_hole('O'), true);
    cr_assert_eq(is_good_char('P'), true);
    cr_assert_eq(is_good_char(' '), true);
    cr_assert_eq(is_good_char('d'), false);
    cr_assert_eq(check_map("maps/tests/test1", buffer), 0);
    cr_assert_eq(check_map("maps/tests/test3", buffer2), 84);
    cr_assert_eq(check_map("maps/tests/test4", buffer3), 84);
    cr_assert_eq(check_error("maps/tests/test1", env2), 84);
    cr_assert_eq(check_error("maps/tests/test1", env0), 84);
    cr_assert_eq(check_error("maps/tests/test22", env0), 84);
    cr_assert_eq(check_error("maps/tests/test1", env1), 0);
}
