/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** display ascending order two digit numbers
*/

void my_putchar(char c);

void display_num(int a, int b, int c, int d)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    if (a == '9' && b == '8')
        return;
    else {
        my_putchar(',');
        my_putchar(' ');
    }
}

void calcul(int a, int b, int c)
{
    int d = '1';

    for (d; a <= '9' && b <= '9' && c <= '9' ; d++) {
        display_num(a, b, c, d);
        if (b >= '9' && c >= '9' && d >= '9') {
            a++;
            b = '0';
            c = a;
            d = b;
        }
        if (c >= '9' && d >= '9') {
            b++;
            c = a;
            d = b;
        }
        if (d >= '9') {
            c++;
            d = 47;
        }
    }
}

int my_print_comb2(void)
{
    int a = '0';
    int b = '0';
    int c = '0';
    calcul(a, b, c);
    return (0);
}
