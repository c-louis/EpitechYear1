/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** return the root if it's a whole number
*/

int my_compute_square_root(int nb)
{
    int square = 0;
    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    while (square < nb) {
        if (square * square == nb)
            return (square);
        if (square * square > nb)
            return (0);
        square++;
    }
    return (0);
}
