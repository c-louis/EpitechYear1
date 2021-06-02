/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** print all the parameters on new line
*/

void my_putstr(char *str);

void my_putchar(char c);

void my_rev_params(int argc, char **argv)
{
    int i = argc;
    while (i > 0) {
        my_putstr(argv[i - 1]);
        my_putchar('\n');
        i--;
    }
}
