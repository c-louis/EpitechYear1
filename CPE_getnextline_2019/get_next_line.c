/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int r;

int contain_line(char *str)
{
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == '\n')
            return (1);
    }
    return (0);
}

int contain_line_f(char *str)
{
    if (str[r] == '\0')
        return (1);
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == '\n')
            return (1);
    }
    return (0);
}

char *push_str(char *str)
{
    int i = 0;
    int size = 0;
    char *to_return;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    for (; str[size] != '\0'; size++);
    to_return = malloc(i+1);
    (*buffer) = malloc(size-i+1);
    for (int y = 0; y < i; y++)
        to_return[y] = str[y];
    to_return[i] = '\0';
    if (to_return[0] == '\0' && r == 0)
        return (0);
    for (int y = 0; str[y+i+1] != '\0'; y++)
        (*buffer)[y] = str[y+1+i];
    (*buffer)[size-i] = '\0';
    return (to_return);
}

void merge_str(char **txt, char *buf)
{
    char *tmp;
    int txt_len = 0;
    int tmp_len = 0;

    for (; (*txt)[txt_len] != '\0'; txt_len++);
    for (; buf[tmp_len] != '\0'; tmp_len++);
    tmp = malloc(txt_len + tmp_len + 1);
    for (int i = 0; i < txt_len; i++)
        tmp[i] = (*txt)[i];
    for (int i = 0; i < tmp_len; i++)
        tmp[txt_len + i] = buf[i];
    tmp[txt_len+tmp_len] = '\0';
    *txt = tmp;
}

char *get_next_line(int fd)
{
    int is_line = 0;
    char buf[READ_SIZE];
    char *txt = malloc(1);
    txt[0] = '\0';
    if (buffer == NULL)
        buffer = malloc(sizeof(char *));
    if (buffer != NULL && *buffer != NULL && contain_line(*buffer))
        return (push_str(*buffer));
    else if (buffer != NULL && *buffer != NULL && (!contain_line(*buffer)))
        merge_str(&txt, *buffer);
    while (is_line != 1 && fd != -1 && READ_SIZE > 0) {
        r = read(fd, buf, READ_SIZE);
        buf[r] = '\0';
        if (r != 0) {
            merge_str(&txt, buf);
            is_line = contain_line_f(txt);
        } else
            break;
    }
    return (push_str(txt));
}
