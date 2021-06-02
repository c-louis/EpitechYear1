/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** Stdin Reader
*/

#include <unistd.h>
#include "inf_utils.h"

char *get_input(int size)
{
    char buf[size + 1];
    int bytes_read;

    bytes_read = read(fd, buf, size);
    if (bytes_read != size)
        return (0);
    buf[size] = '\0';
    return (buf);
}
