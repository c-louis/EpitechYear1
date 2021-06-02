/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** display numbers in ascending order
*/

void my_putchar(char c);

void display_digit(int f_digit, int s_digit, int t_digit)
{
    my_putchar(f_digit);
    my_putchar(s_digit);
    my_putchar(t_digit);
    if (f_digit != '7') {
        my_putchar(',');
        my_putchar(' ');
    }

}

int my_print_comb(void)
{
    int f_digit = '0';
    int s_digit = '1';
    int t_digit = '2';

    while (f_digit != '8')
    {
        display_digit(f_digit, s_digit, t_digit);
        t_digit += 1;
        if (t_digit == ':') {
            s_digit += 1;
            t_digit = s_digit + 1;
            if (s_digit == '9') {
                f_digit += 1;
                s_digit = f_digit + 1;
                t_digit = s_digit +1;
            }
        }
    }
}
