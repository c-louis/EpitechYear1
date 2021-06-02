/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the given number
*/

void my_putchar(char c);

int ten_power(int power)
{
    int to_return = 10;

    if (power == 0) {
        return (1);
    }
    else if (power == 1)
        return (10);
    else {
        power--;
        for (power ; power > 0; power--) {
            to_return = to_return * 10;
        }
    }
    return to_return;
}

int determine_nb_size(int nb)
{
    int i = 0;

    for (i; nb >= 10 || nb <= -10; i++) {
        nb /= 10;
    }
    return (i);
}

void display_all(int nb_size, int nb)
{
    int tmp_nb;

    while (nb_size >= 0) {
        tmp_nb = nb / (ten_power(nb_size));
        if (tmp_nb < 0)
            tmp_nb = tmp_nb * -1;
        if (tmp_nb >= 10) {
            tmp_nb = tmp_nb % 10;
        }
        tmp_nb = tmp_nb + 48;
        my_putchar(tmp_nb);
        nb_size--;
        if (nb == -2147483648 && nb_size == 0)
            nb_size--;
    }
}

int my_put_nbr(int nb)
{
    int nb_size;

    nb_size = determine_nb_size(nb);
    if (nb < 0)
        my_putchar('-');
    display_all(nb_size, nb);
    if (nb == -2147483648)
        my_putchar(56);
    return (0);
}
