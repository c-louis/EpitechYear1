/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Graphic functions header
*/

#ifndef _graph_h
#define _graph_h

typedef struct bullet_impact {
    sfSprite *impact;
    int display_time;
} bullet_t;

typedef struct sound {
    sfSound *shoot;
    sfSound *hit_s;
    sfSound **oldsounds;
} sound_t;

typedef struct game_stat {
    unsigned int score;
    sfText *score_txt;
    unsigned int hit;
    unsigned int shot_missed;
    unsigned int pigeon_missed;
    unsigned int state;
} game_stat_t;

typedef struct pigeon {
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect hitbox;
    int movement;
    int speed;
} pigeon_t;

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

typedef struct menu_struct {
    image_t *pointer;
    sfRectangleShape *background;
    sfRectangleShape *start_button;
    sfRectangleShape *exit_button;
    sfRectangleShape *credit_button;
    sfRectangleShape *expli_button;
    sfText *title;
    sfText *start_txt;
    sfText *pause_txt;
    sfText *resume_txt;
    sfText *exit_txt;
    sfText *credit_txt;
    sfText *expli_txt;
} menu_t;

typedef struct explication_struct {
    sfRectangleShape *background;
    image_t *close_img;
    image_t *echap_img;
    image_t *mouse_img;
    sfText *echap_txt;
    sfText *mouse_txt;
    sfText *title;
} explication_t;

typedef struct credit_struct {
    sfText *title;
    sfText *fond;
    sfText *pigeon;
    sfText *shoot;
    sfText *death;
    sfText *impact;
} credit_t;

typedef struct glgraph {
    int tick;
    int ammo;
    char *gamemode;
    sfFont *arial;
    sfFont *bitwonder;
    sfText *score;
    sfTexture *pigeon_texture;
    sfTexture *bullet_texture;
    image_t *fond;
    image_t *pointer;
    image_t *ammo_i;
    pigeon_t **pig_list;
    pigeon_t **dead_pigeon;
    game_stat_t *game;
    sound_t *sounds;
    bullet_t **bullets;
    menu_t *menu;
    credit_t *credit;
    explication_t *expli;
    sfSoundBuffer *shoot_sb;
    sfSoundBuffer *hit_sb;
    sfRenderWindow *window;
    sfClock *gameclock;
} glg_t;

/* Utils function */
char *get_starting_pointer(char *s);
int get_nbrsize(unsigned int nbr);
char *my_int_char(unsigned int nbr);

/* pigeon animation */
void animate_pigeon(glg_t *gl);
int move_y(pigeon_t *pigeon);
void move_pigeon(glg_t *gl);
void animate_dead_pigeon(glg_t *gl);

/* Event function */
void process_event(sfRenderWindow *window, sfEvent *event, glg_t *gl);
void dispatch_focus_event(sfRenderWindow *window, sfEvent *event, glg_t *gl);
void key_pressed(sfEvent *event, glg_t *gl);
void add_bullet(glg_t *gl, bullet_t *bullet);
void handle_shoot_bullet(glg_t *gl, sfMouseButtonEvent date);
void kill_pigeon(glg_t *gl, int killed);
void check_hit_pos(sfMouseButtonEvent data, glg_t *gl);
void click_handler(sfEvent *event, glg_t *gl);
void set_pointer_pos(sfMouseMoveEvent mouse, glg_t *gl);
unsigned int my_rand(void);
void render_bullet(sfRenderWindow *window, bullet_t *bullet);
void update_score(glg_t *gl, int to_add);

/* Shoot event function */
void add_bullet(glg_t *gl, bullet_t *bullet);
void handle_shoot_bullet(glg_t *gl, sfMouseButtonEvent data);
void handle_shoot_bullet(glg_t *gl, sfMouseButtonEvent data);
void kill_pigeon(glg_t *gl, int killed);
void check_hit_pos(sfMouseButtonEvent data, glg_t *gl);
void set_ammo_rect(glg_t *gl);
void render_bullet(sfRenderWindow *window, bullet_t *bullet);
void reload(glg_t *gl);

/* Pigeon list */
void make_new_pigeon(pigeon_t *new_pig, glg_t *gl);
void add_pigeon(glg_t *gl);
void remove_pigeon(glg_t *gl, int delete);
void check_pigeon(glg_t *gl);
void add_dead_pigeon(glg_t *gl, pigeon_t *to_add);
void remove_dead_pigeon(glg_t *gl, int delete);

/* Sound gestion */
void add_sound(glg_t *gl, sfSound *sound);
void remove_sound(glg_t *gl);
void handle_shoot_sound(glg_t *gl);
void handle_hit_sound(glg_t *gl);

/*Init function */
void init_game(glg_t *gl);
void init_sound(glg_t *gl);
void init_bullets(glg_t *gl);
void init_pigeon(glg_t *gl);
void init_global(glg_t *gl);
void init_font(glg_t *gl);
void init_fond(glg_t *gl);
void init_pointer(glg_t *gl);

/*Init menu function */
void init_menu_background(glg_t *gl);
void init_menu_startbutton(glg_t *gl);
void init_menu(glg_t *gl);
void init_menu_pausebutton(glg_t *gl);
void init_menu_exitbutton(glg_t *gl);
void init_menu_creditbutton(glg_t *gl);
void init_menu_explibutton(glg_t *gl);
void init_text_sprite_expli(glg_t *gl);
void init_sprite_pos(glg_t *gl);
void set_all_policy_size(glg_t *gl);
void set_all_position(glg_t *gl);
void set_all_text(glg_t *gl);
void init_all_text(glg_t *gl);
void init_credit(glg_t *gl);
void init_explication(glg_t *gl);

/*Memory clean function */
void close_window(sfRenderWindow *window);
void clean_font(glg_t *gl);
void clean_texture_image(glg_t *gl);
void clean_menu(glg_t *gl);
void clean_game(glg_t *gl);
void clean_all(glg_t *gl);
void clean_pigeon_list(glg_t *gl);
void clean_sounds(glg_t *gl);
void clean_bullet(glg_t *gl);

/* Loop function */
void game_loop(sfRenderWindow *window, glg_t *gl);
void main_loop(sfRenderWindow *window, glg_t *gl);
void game_draw_loop(sfRenderWindow *window, glg_t *gl);
void pigeon_loop(glg_t *gl);
void menu_loop(sfRenderWindow *window, glg_t *gl);
void pause_loop(sfRenderWindow *window, glg_t *gl);
void explication_loop(sfRenderWindow *window, glg_t *gl);
void credit_loop(sfRenderWindow *window, glg_t *gl);

#endif
