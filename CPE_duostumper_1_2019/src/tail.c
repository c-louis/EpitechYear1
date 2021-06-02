/*
** EPITECH PROJECT, 2020
** tail
** File description:
** tail handling
*/

#include <stddef.h>
#include <stdio.h>

#include "my.h"
#include "project.h"

int tail_byte_start(struct options *opt, char **files)
{
    char *text = NULL;
    int size = 0;
    int start = 0;
    int line_pass = 0;

    for (int i = 0; files[i]; i++) {
        text = read_file(files[i]);
        if (text == NULL) {
            print_err_open(files[i], opt);
            continue;
        }
        if ((++line_pass) != 1)
            my_printf("\n");
        print_verbose(files[i], opt);
        my_printf("%s", text + (opt->bytes - 1));
    }
    return (0);
}

int tail_start(struct options *opt, char **files)
{
    char **parsed = NULL;
    int line_pass = 0;

    if (opt->bytes != -1)
        return (tail_byte_start(opt, files));
    for (int i = 0; files[i]; i++) {
        parsed = get_parsed(files[i]);
        if (parsed == NULL) {
            print_err_open(files[i], opt);
            continue;
        }
        if ((++line_pass) != 1)
            my_printf("\n");
        print_verbose(files[i], opt);
        for (int y = opt->lines - 1; parsed[y]; y++) {
            my_printf("%s", parsed[y]);
            if (parsed[y+1])
                my_printf("\n");
        }
    }
}

int tail_byte_basic(struct options *opt, char **files)
{
    char *text = NULL;
    int size = 0;
    int start = 0;
    int line_pass = 0;

    for (int i = 0; files[i]; i++) {
        text = read_file(files[i]);
        if (text == NULL) {
            print_err_open(files[i], opt);
            continue;
        }
        size = my_strlen(text);
        start = size - opt->bytes;
        if ((++line_pass) != 1)
            my_printf("\n");
        print_verbose(files[i], opt);
        my_printf("%s", text + start);
    }
    return (0);
}

int tail_basic(struct options *opt, char **files)
{
    char **parsed = NULL;
    int start = 0;
    int line_pass = 0;

    if (opt->bytes != -1)
        return (tail_byte_basic(opt, files));
    for (int i = 0; files[i]; i++) {
        parsed = get_parsed(files[i]);
        if (parsed == NULL) {
            print_err_open(files[i], opt); continue;
        }
        if ((++line_pass) != 1) my_printf("\n");
        print_verbose(files[i], opt);
        for (; parsed[start] != NULL; start++);
        start = start - opt->lines < 0 ? 0 : (start - (opt->lines+1));
        for (int y = start; parsed[y]; y++) {
            my_printf("%s", parsed[y]);
            if (parsed[y+1]) my_printf("\n");
        }
    }
    return (0);
}

int tail(struct options *opt, char **files)
{
    opt->ret = 0;
    if (opt->start == 1)
        return (tail_start(opt, files));
    else
        return (tail_basic(opt, files));
}
