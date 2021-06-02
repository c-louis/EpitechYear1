/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** print all the parameters on new line
*/

void my_putstr(char *str);

void my_putchar(char c);

void my_print_params(int argc, char **argv)
{
    int i = 0;
    while (i < argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
}
