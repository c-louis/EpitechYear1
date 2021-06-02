/*
** EPITECH PROJECT, 2019
** map
** File description:
** map handling function
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sokoban.h"
#include "my.h"

char **make_map(char *m_map, gsoko_t *gl)
{
    char **map = malloc(sizeof(char *) * (gl->row+1));
    int size = 0;
    int index_overall = 0;

    for (int i = 0; i < gl->row; i++) {
        size = 0;
        for (size;m_map[size+index_overall] != '\n'
            && m_map[size+index_overall] != '\0'; size++);
        char *to_add = malloc(sizeof(char) * (size+1));
        for (int y = 0; y < size; y++) {
            to_add[y] = m_map[index_overall++];
        }
        to_add[size] = '\0';
        map[i] = to_add;
        index_overall++;
    }
    map[gl->row] = 0;
    return (map);
}

char *read_map(char *file)
{
    struct stat buf;
    char *map;
    int fd = open(file, O_RDONLY);

    stat(file, &buf);
    map = malloc(sizeof(char)*(buf.st_size+1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = 0;
    close(fd);
    return (map);
}

int get_mapcolumn(char *map)
{
    int i = 0;
    while (map[i] != '\n')
        i++;
    return (i);
}

int get_maprow(gsoko_t *gl)
{
    int char_count = 0;
    for (int i = 0; gl->smap[i] != '\0'; i++) {
        if (gl->smap[i] == '\n')
            char_count++;
    }
    return (char_count+1);
}
