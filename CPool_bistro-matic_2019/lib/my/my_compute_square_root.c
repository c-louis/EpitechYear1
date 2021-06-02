/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Compute the square root of a number
** if input is a perfect square
*/

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return nb;
    for (int i = 0; i * i <= nb; i++) {
        if (i * i == nb)
            return (i);
    }
    return (0);
}
