/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** open_map
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (-1);
    return (fd);
}

int length_of_file(int fd_file)
{
    int len = 0;
    int size = 0;
    char buf[16];

    while ((len = read(fd_file, buf, 15)) > 0)
        size = size + len;
    if (lseek(fd_file, 0, SEEK_SET) == -1)
        return (-1);
    return (size);
}

char *read_file(int fd_file)
{
    int len_file = length_of_file(fd_file);
    char buf[1];
    char *map = NULL;

    if (len_file == -1 || len_file != 32)
        return (NULL);
    map = malloc(sizeof(char) * len_file + 1);
    if (!map)
        return (NULL);
    map[len_file] = '\0';
    for (int i = 0; i < len_file; i++) {
        if (lseek(fd_file, i, SEEK_SET) == -1)
            return (NULL);
        read(fd_file, buf, 1);
        map[i] = buf[0];
    }
    return (map);
}

char **open_file(char *path_file)
{
    int fd_file = fs_open_file(path_file);
    char *map = NULL;
    char **map_final = NULL;

    if (fd_file == -1)
        return (NULL);
    map = read_file(fd_file);
    if (!map)
        return (NULL);
    map_final = my_str_to_word_array(map);
    free(map);
    if (!map_final)
        return (NULL);
    return (map_final);
}