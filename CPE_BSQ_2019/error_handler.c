/*
** EPITECH PROJECT, 2019
** error_handler
** File description:
** check error
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "bsq_struct.h"
#include "my.h"

int check_map_error(gbsq_t *gl)
{
    char *map = gl->string_map;
    int par_c = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            par_c++;
        }
    }
    if (par_c != gl->row)
        return (84);
    return (0);
}

int check_error(int ac , char **av)
{
    int fd = open(av[1], O_DIRECTORY);
    if (fd == 3)
        return (84);
    close(fd);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    close(fd);
    return (0);
}

char *read_all(char *file)
{
    int fd;
    int len = 0;
    int size = 0;
    char *buffer;
    char buf[16];
    fd = open(file, O_RDONLY);
    while ((len = read(fd, buf, 15)) > 0) {
        size = size + len;
    }
    close(fd);
    fd = open(file, O_RDONLY);
    buffer = malloc(size + 1);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
