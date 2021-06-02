/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** header for the screensaver
*/

#define MAX_ANIM = 5

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct line {
    int x1;
    int y1;
    int x2;
    int y2;
} line_t;

typedef struct anim_line {
    line_t **lines;
} animline_t;

typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct glgraph {
    int is_updating;
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *framebuffer;
    int init;
    int anim;
    animline_t *line_anim;
    sfClock *clock;
} glmul_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void update_sprite_from_framebuffer(glmul_t *gl);
void put_pixel(framebuffer_t *fb, unsigned int x,
    unsigned int y, sfColor color);
void mandelbrot(framebuffer_t *fb, int n);
sfColor random_color(void);
void make_random_line(line_t *line);
void line_anim(glmul_t *gl);
void circle_anim(glmul_t *gl);
void init_all(glmul_t *gl);
void process_event(sfRenderWindow *window, sfEvent *event, glmul_t *gl);
void draw_line(framebuffer_t *fb, line_t *line);
int get_lines_count(line_t **lines);
void cleanup_framebuffer(glmul_t *gl);
void print_help(void);
void print_details(void);
