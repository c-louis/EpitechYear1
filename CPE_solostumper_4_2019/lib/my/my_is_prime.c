/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** is_prime todo
*/

int my_is_even(int nb)
{
    if (nb % 2 == 0)
        return (1);
    return (0);
}

int my_compute_square_root(int nb);

int my_is_prime(int nb)
{
    int k = 3;
    if (nb < 2)
        return (0);
    if (nb == 2)
        return (1);
    if (my_is_even(nb) == 1)
        return (0);
    if (my_compute_square_root(nb) != 0)
        return (0);
    while (k < nb)
    {
        if (nb % k == 0)
            return (0);
        k += 2;
    }
    return (1);
}
