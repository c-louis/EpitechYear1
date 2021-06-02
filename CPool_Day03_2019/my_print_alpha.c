/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** displays the lowercase alphabet in ascending order
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (int i = 97; i < 123; i++) {
        my_putchar(i);
    }
    my_putchar(10);
    return (0);
}
