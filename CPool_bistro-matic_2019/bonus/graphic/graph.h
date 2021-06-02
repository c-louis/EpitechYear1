/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Graphic functions header
*/

#ifndef _graph_h
#define _graph_h

typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct topbar {
    sfText *basic;
    sfText *button;
} topbar_t;

typedef struct globals {
    int calc_mode;
    sfTexture *tex;
    sfImage *image;
    int init;
    framebuffer_t *fb;
    sfSprite *pix;
    char *old_in;
    int is_updating;
    sfVideoMode mode;
    sfText *in;
    sfText **result;
    sfFont *font;
    int scroll_pos;
    int cursor_pos;
    int blink_count;
    topbar_t *bartext;
} globals_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor);
sfSprite *create_sprite_from_framebuffer(globals_t *fb, sfVideoMode *mode);
void draw_square(framebuffer_t *fb, sfVector2u pos, int size, sfColor);
void draw_rect(framebuffer_t *fb, sfIntRect rect, sfColor c);
void draw_borders(framebuffer_t *fb, sfIntRect rect, int margin, sfColor c);
void cleanup_framebuffer(globals_t *gl);
void text_entered(char in, globals_t *gl);
void key_pressed(sfKeyCode key, globals_t *gl);
void scroll(float delta, globals_t *gl);
void draw_cursor(int pos, globals_t *gl);
void set_sftext(sfText **txt, sfVector2f pos, char *str, sfFont *font);
void change_mode(sfEvent *event, globals_t *gl);
void draw_topbar_text(globals_t *gl, sfRenderWindow *window);
void init_topbar(globals_t *gl);
void draw_topbar_box(framebuffer_t *fb);
void dispatch_focus_event(sfRenderWindow *window, sfEvent *event);
void process_event(sfRenderWindow *window, sfEvent *event, globals_t *gl);
void draw_scrollbar(globals_t *gl);
void scroll(float delta, globals_t *gl);
void scroll_to_bottom(globals_t *gl);
void scroll_up(globals_t *gl);
void init_globals(globals_t *gl);
void init_window(globals_t *gl);
int my_len(sfText **thing);
void key_pressed(sfKeyCode key, globals_t *gl);
void blinker(globals_t *gl);
void remove_cursor(int pos, globals_t *gl);
void draw_cursor(int pos, globals_t *gl);
void translate_text(globals_t *gl);
void create_text(char *str, int is_result, globals_t *gl);
void push_expr(char const *expr, globals_t *gl);
void add_char(char *dest, globals_t *gl, char const *current, char c);
void remove_char(char *dest, globals_t *gl, char const *current);
void text_entered(char c, globals_t *gl);
char *carriage(char *src);
int count_carriage(char const *src);
float get_posy(globals_t *gl, int len);
void draw_keyboard(globals_t *gl, sfRenderWindow *window);

#endif
