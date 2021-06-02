/*
** EPITECH PROJECT, 2019
** cat
** File description:
** approximative reproduction of system cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "my.h"

void errorz(int error, char *file)
{
    my_put_nbr(error);
    my_putstr("cat: ");
    my_putstr(file);
    my_putstr(": ");
    if (error != 0)
        my_putstr(strerror(errno));
    else
        my_putstr("Is a directory");
    my_putchar('\n');
}

void read_and_write(char *file)
{
    int fd;
    char buffer[32];
    int size = 32;

    if (open(file, O_DIRECTORY) == 3) {
        errorz(errno, file);
        return; }
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        errorz(errno, file);
    }
    else {
        while (size > 0) {
            size = read(fd, buffer, 31);
            buffer[size] = '\0';
            if (size != 0) {
                my_putstr(buffer);
            }
        }
    }
    close(fd);
}

int main_bin(int ac, char **argc)
{
    if (ac > 1) {
        for (int i = 1; i < ac; i++) {
            read_and_write(argc[i]);
        }
    }
    else {
        char buffer[32];
        while(1) {
            int size = read(0, buffer, 31);
            buffer[size] = '\0';
            my_putstr(buffer);
        }
    }
    return (0);
}
