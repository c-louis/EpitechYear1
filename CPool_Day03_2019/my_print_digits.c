/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** displays all the digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = 48; i < 58; i++) {
        my_putchar(i);
    }
    my_putchar(10);
    return (0);
}
