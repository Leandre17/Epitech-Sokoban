/*
** EPITECH PROJECT, 2022
** tncs
** File description:
** test
*/

#include <ncurses.h>
#ifndef TEST_H_
    #define TEST_H_
    #define Terminal_low "Terminal trop petit"
    #include <ncurses.h>

typedef struct map_s {
    char **map;
    char *save;
    int nb_rows;
    int nb_cols;
    int filled;
    int to_fill;
} map_t;

typedef enum direction{
    UP,
    DOWN,
    RIGHT,
    LEFT
} way_e;

typedef struct box_s {
    int x;
    int y;
    struct box_s *next;
} box_t;

typedef struct player_s {
    int posx;
    int posy;
    int maxx;
    int maxy;
    int minx;
    int miny;
    map_t *map;
    int ch;
    int box;
    int block;
    box_t *boxs;
} player_t;

player_t *game_loop(player_t *player);

int start(char const *filename);
player_t *init_player(char const *filename);
player_t *play_loop(player_t *player);
player_t *get_player_pos(player_t *player);
player_t *reset_map(player_t *player);

player_t *move_player_right(player_t *player);
player_t *move_player_down(player_t *player);
player_t *move_player_up(player_t *player);
player_t *move_player_left(player_t *player);
player_t *move_box_left(player_t *player);
player_t *move_box_right(player_t *player);
player_t *move_box_down(player_t *player);
player_t *move_box_up(player_t *player);
bool can_move(player_t *player, way_e way);
player_t *can_be_moved(player_t *player);
player_t *find_pos_bos(player_t *player);
int new_pos(int pos, int max, bool before, int speed);
box_t *box_init(player_t *player);

player_t *map_init(char const *filename, player_t *player);
player_t *transform_map(player_t *player);
char **load_2d_arr_from_file(char const *str , int nb_rows , int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
void print_map(char **map);
int find_col(char **array);
int find_row(char *str);
int usage(void);
int check_error(char const *filepath, char **env);
bool is_good_char(char ch);
bool is_player(char ch);
bool is_hole(char ch);
bool is_box(char ch);
int check_map(char const *filepath, char *map);
bool check_move(int posx, int posy, player_t *player);
#endif
