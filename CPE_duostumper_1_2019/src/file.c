/*
** EPITECH PROJECT, 2020
** tail
** File description:
** tail file handling
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "project.h"

int get_file_size(char *file)
{
    int fd = open(file, O_RDONLY);
    int len = 0;
    int size = 0;
    char buf[16];

    while ((len = read(fd, buf, 15)) > 0)
        size += len;
    return (size);
}

int get_line_count(char *text)
{
    int line = 1;

    for (int i = 0; text[i]; i++) {
        if (text[i] == '\n')
            line++;
    }
    return (line);
}

char **get_parsed(char *file)
{
    char *text = read_file(file);
    char **parsed = NULL;

    if (text == NULL)
        return (NULL);
    parsed = parse_text(text);
    if (parsed == NULL)
        return (NULL);
    return (parsed);
}

char **parse_text(char *text)
{
    int line = get_line_count(text);
    int size = 0;
    int ol = 0;
    char **parsed = NULL;

    parsed = malloc(sizeof(char *) * (line+1));
    if (parsed == NULL)
        return (NULL);
    for (int i = 0; i < line; i++) {
        for (size = 0; text[size+ol] != '\n' && text[size+ol] != '\0'; size++);
        char *str = malloc(sizeof(char) * (size + 1));
        if (str == NULL) return (NULL);
        for (int y = 0; y < size; y++) str[y] = text[ol++];
        str[size] = '\0';
        parsed[i] = str;
        parsed[i+1] = NULL;
        ol++;
    }
    return (parsed);
}

char *read_file(char *file)
{
    char *text;
    int fd = open(file, O_RDONLY);
    int size = 0;

    if (fd == -1)
        return (NULL);
    size = get_file_size(file);
    text = malloc(size + 1);
    if (text == NULL)
        return (NULL);
    read(fd, text, size);
    close(fd);
    text[size] = '\0';
    return (text);
}
