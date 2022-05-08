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

/**
 * @brief struct that contain all the map info
 * 
 * @param map the map that is played by the player
 * @param save the map whith no modification made by the player
 * @param nb_rows the number of rows in the map
 * @param nb_col the number of cols in the map
 * @param filled number of box in holles
 * @param to_fill number of holles
 */
typedef struct map_s {
    char **map; /** */
    char *save;
    int nb_rows;
    int nb_cols;
    int filled;
    int to_fill;
} map_t;

/**
 * @brief direction enum
 * 
 */
typedef enum direction {
    UP,
    DOWN,
    RIGHT,
    LEFT
} way_e;

/**
 * @brief enum type
 * 
 */
typedef enum type {
    play,
    edit,
    file
} menu_e;

/** 
 * @struct box_s
 * @brief box struct
 * 
 * @param x pos x of the box
 * @param y pos y of the box
 * @param next the next box
 */
typedef struct box_s {
    int x;
    int y;
    struct box_s *next;
} box_t;

/**
 * @brief struct to make a vector with 2 cordonate
 * 
 * @param x coordonate x
 * @param y coordonate y
 */
typedef struct vct_s {
    int x;
    int y;
} vct_t;

/**
 * @brief menu struct
 * 
 * @param type enum of the menu type
 * @param chosen the chosen menu
 * @param pos pos
 * @param new_map the new map when in edition mode
 */
typedef struct menu_s {
    enum type type;
    int chosen;
    vct_t pos;
    char **new_map;
} menu_t;

/** 
 * @struct player_s
 * @brief player struct
 * 
 * @param pos current position of the player
 * @param max the position max of the player
 * @param min the position min of the player
 * @param map the map structure where the player move
 * @param ch the char enter by the player
 * @param box number of box in the map
 * @param block is box blocked
 * @param menu the menu struct of the game
 * @param boxs the boxs struts that contain all the boxs
 * @param win the player window
 */
typedef struct player_s {
    vct_t pos;
    vct_t max;
    vct_t min;
    map_t *map;
    int ch;
    int box;
    int block;
    menu_t menu;
    box_t *boxs;
    WINDOW *win;
} player_t;

/**
 * @brief The main loop of the game.
 * 
 * @param player 
 */
void game_loop(player_t *player);

/**
 * @brief initialisation of the screen
 * 
 */
void init_win(void);

/**
 * @brief start the game with a path to a map
 * 
 * @param filename 
 * @return int 
 */
int start(char const *filename);

/**
 * @brief initialisation of the player
 * 
 * @param filename 
 * @return player_t* 
 */
player_t *init_player(char const *filename);

/**
 * @brief main loop for the player mouvement
 * 
 * @param player 
 */
void play_loop(player_t *player);

/**
 * @brief Get the player pos in the map
 * 
 * @param player 
 */
void get_player_pos(player_t *player);

/**
 * @brief reset the map
 * 
 * @param player 
 */
void reset_map(player_t *player);

/**
 * @brief display map
 * 
 * @param player 
 */
void show_map(player_t *player);

/**
 * @brief check if a map is valid or not
 * 
 * @param map 
 * @return int 
 */
int check_map(char *map);

/**
 * @brief move player right
 * 
 * @param player 
 */
void move_player_right(player_t *player);

/**
 * @brief move player down
 * 
 * @param player 
 */
void move_player_down(player_t *player);

/**
 * @brief move player up
 * 
 * @param player 
 */
void move_player_up(player_t *player);

/**
 * @brief move player left
 * 
 * @param player 
 */
void move_player_left(player_t *player);

/**
 * @brief move box left
 * 
 * @param player 
 */
void move_box_left(player_t *player);

/**
 * @brief move box right
 * 
 * @param player 
 */
void move_box_right(player_t *player);

/**
 * @brief move box down
 * 
 * @param player 
 */
void move_box_down(player_t *player);
void move_box_up(player_t *player);

/**
 * @brief check if a box can move
 * 
 * @param player 
 * @param way 
 * @return true 
 * @return false 
 */
bool can_move(player_t *player, way_e way);

/**
 * @brief check if a box can be moved 
 * 
 * @param player 
 */
void can_be_moved(player_t *player);

/**
 * @brief find box pos
 * 
 * @param player 
 */
void find_pos_bos(player_t *player);

/**
 * @brief return a new pos 
 * 
 * @param pos 
 * @param max 
 * @param before 
 * @param speed 
 * @return int 
 */
int new_pos(int pos, int max, bool before, int speed);

/**
 * @brief initialisation of all the boxs
 * 
 * @param player 
 * @return box_t* 
 */
box_t *box_init(player_t *player);

/**
 * @brief initialisation of the map
 * 
 * @param filename 
 * @param player 
 */
void map_init(char const *filename, player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void transform_map(player_t *player);

/**
 * @brief 
 * 
 * @param str 
 * @param nb_rows 
 * @param nb_cols 
 * @return char** 
 */
char **load_2d_arr_from_file(char const *str, int nb_rows, int nb_cols);
/**
 * @brief 
 * 
 * @param nb_rows 
 * @param nb_cols 
 * @return char** 
 */
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
/**
 * @brief 
 * 
 * @param filepath 
 * @return char* 
 */
char *load_file_in_mem(char const *filepath);
/**
 * @brief 
 * 
 * @param map 
 */
void print_map(char **map);
/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int find_row(char *str);
/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int find_col(char *str);

/**
 * @brief 
 * 
 * @return int 
 */
int usage(void);

/**
 * @brief 
 * 
 * @param filepath 
 * @return int 
 */
int check_error(char const *filepath);

/**
 * @brief 
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
bool is_good_char(char ch);

/**
 * @brief 
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
bool is_player(char ch);

/**
 * @brief 
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
bool is_hole(char ch);

/**
 * @brief 
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
bool is_box(char ch);


/**
 * @brief 
 * 
 * @param player 
 */
void menu_menu(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void print_menu_edit(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void print_menu_file(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void menu_display(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void all_edit_menu(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void all_file_menu(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void open_map(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void quit_menu(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void delete_win(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void new_map(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 * @param filename 
 */
void premaid_map(player_t *player, char *filename);

/**
 * @brief end menu
 * 
 * @param player 
 */
void end_menu(player_t *player);

/**
 * @brief Create a menu object
 * 
 * @param player 
 */
void create_menu(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void modify_menu(player_t *player);

/**
 * @brief 
 * 
 * @param chosen 
 * @return int 
 */
int start_menu(int chosen);

/**
 * @brief 
 * 
 * @param filepath 
 * @return int 
 */
int check_new_map(char const *filepath);

/**
 * @brief 
 * 
 * @param player 
 */
void edit_current_map(player_t *player);

/**
 * @brief Create a map menu object
 * 
 * @param player 
 */
void create_map_menu(player_t *player);

/**
 * @brief Create a new map object
 * 
 * @param player 
 */
void create_new_map(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void fill_new_map(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void show_new_map(player_t *player);

/**
 * @brief 
 * 
 * @param player 
 */
void save_map(player_t *player);

/**
 * @brief 
 * 
 * @param msg 
 * @return char* 
 */
char *my_get_str(char *msg);

/**
 * @brief Create a new menu object
 * 
 * @param player 
 */
void create_new_menu(player_t *player);

/**
 * @brief play map
 * 
 * @param player 
 */
void play_map(player_t *player);


/**
 * @brief save & play
 * 
 * @param player 
 */
void save_play(player_t *player);

/**
 * @brief quit edit menu
 * 
 * @param player 
 */
void quit_edit(player_t *player);

/**
 * @brief cancel choice and return to edit menu
 * 
 * @param player 
 */
void cancel_choice(player_t *player);

/**
 * @brief find all hole
 * 
 * @param str 
 * @return int 
 */
int find_all_complete(char *str);
#endif
