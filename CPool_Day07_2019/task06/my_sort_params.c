/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** print all the parameters on new line sorted by ascii
*/

void my_putstr(char *str);

void my_putchar(char c);

void check_print(int index, char *arg)
{
    if (index == arg[0]) {
        my_putstr(arg);
        my_putchar('\n');
    }
}

void my_sort_params(int argc, char **argv)
{
    int i = 31;
    while (i < 127) {
        for (int y = 0; y < argc; y++) {
            check_print(i, argv[y]);
        }
        i++;
    }
}
