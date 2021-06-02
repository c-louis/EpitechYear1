/*
** EPITECH PROJECT, 2019
** text_handler
** File description:
** hander for the text
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"
#include "eval.h"

void create_text(char *str, int is_result, globals_t *gl)
{
    int i = 0;
    int y = 0;
    sfVector2f pos;
    int len = my_len(gl->result);

    gl->result[len] = sfText_create();
    sfText_setFont(gl->result[len], gl->font);
    sfText_setColor(gl->result[len], sfBlack);
    sfText_setCharacterSize(gl->result[len], 18);
    sfText_setString(gl->result[len], str);
    pos.x = is_result ? gl->mode.width -
        sfText_getLocalBounds(gl->result[len]).width - 10 : 3;
    pos.y = get_posy(gl, len);
    sfText_setPosition(gl->result[len], pos);
    gl->result[len + 1] = 0;
}

void push_expr(char const *expr, globals_t *gl)
{
    char *copy = carriage((char *)expr);
    char *tmp = eval_expr(expr);
    char *res;
    int len = my_len(gl->result);
    sfText **newResults = malloc(sizeof(sfText *) * (len + 3));

    scroll_to_bottom(gl);
    for (int i = 0; i < len; i++)
        newResults[i] = gl->result[i];
    res = carriage(tmp);
    free(gl->result);
    free(tmp);
    newResults[len] = 0;
    gl->result = newResults;
    create_text(copy, 0, gl);
    create_text(res, 1, gl);
    scroll_up(gl);
    draw_scrollbar(gl);
}

void add_char(char *dest, globals_t *gl, char const *current, char c)
{
    int len = my_strlen(current);

    if (c < 32)
        return;
    remove_cursor(gl->cursor_pos, gl);
    for (int i = 0; i < gl->cursor_pos; i++)
        dest[i] = current[i];
    dest[gl->cursor_pos] = c;
    for (int i = gl->cursor_pos; i < len; i++)
        dest[i + 1] = current[i];
    dest[len + 1] = '\0';
    sfText_setString(gl->in, dest);
    gl->cursor_pos = gl->cursor_pos + 1;
    translate_text(gl);
    draw_cursor(gl->cursor_pos, gl);
}

void remove_char(char *dest, globals_t *gl, char const *current)
{
    int len = my_strlen(current);

    if (gl->cursor_pos <= 0)
        return;
    remove_cursor(gl->cursor_pos, gl);
    for (int i = 0; i < gl->cursor_pos - 1; i++)
        dest[i] = current[i];
    for (int i = gl->cursor_pos; i < len; i++)
        dest[i - 1] = current[i];
    dest[len - 1] = '\0';
    sfText_setString(gl->in, dest);
    gl->cursor_pos = gl->cursor_pos - 1;
    translate_text(gl);
    draw_cursor(gl->cursor_pos, gl);
}

void text_entered(char c, globals_t *gl)
{
    char const *current = sfText_getString(gl->in);
    int len = my_strlen(current);
    char *dest = malloc(len + 2);

    if ((c == '\n' || c == '\r') && len != 0){
        remove_cursor(gl->cursor_pos, gl);
        sfText_setString(gl->in, "");
        push_expr(current, gl);
        gl->cursor_pos = 0;
        translate_text(gl);
        draw_cursor(gl->cursor_pos, gl);
    }else if (c == '\b'){
        remove_char(dest, gl, current);
    }else{
        add_char(dest, gl, current, c);
    }
    free(gl->old_in);
    gl->blink_count = 0;
    gl->old_in = dest;
    gl->is_updating = 1;
}
