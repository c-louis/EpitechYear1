/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** show str
*/

int is_printable(char c)
{
    if (c < 32 || c == 127)
        return (0);
    return (1);
}

int my_showstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {

        if (is_printable(str[i]))
            my_putchar(str[i]);
        else {
            int tmp = (int) str[i];
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_putnbr_base(tmp, "0123456789abcdef");
        }
        i++;
    }
    return (0);
}
