/*
** EPITECH PROJECT, 2019
** my_showmem
** File description:
** show memory hexa and content
*/

int my_strlen(char const *str);

int my_showmem(char const *str, int size)
{
    int str_len = my_strlen(str);
    int i = 1;

    do {
        my_putnbr_base(&str[16 * (i - 1)], "0123456789abcdef");
        my_putchar(':');
        my_putchar(' ');
        for (int y = (i - 1) * 16; y <= (i * 16) - 1; y++) {
            if (y % 2 == 0)
                my_putchar(' ');
            my_putnbr_base(str[y], "0123456789abcdef");
        }
        my_putchar(' ');
        for (int y = (i - 1) * 16; y <= (i * 16) - 1; y++) {
            my_putchar(str[y]);
        }
        my_putchar('\n');
        i++;
    } while (i * 16 < str_len + 15);
}
