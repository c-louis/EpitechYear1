/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** reverse lowercase alphabet
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (int i = 122; i > 96; i--) {
        my_putchar(i);
    }
    my_putchar(10);
    return (0);
}
