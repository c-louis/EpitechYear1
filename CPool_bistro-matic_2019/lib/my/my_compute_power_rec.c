/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Compute the power of n raised to p,
** in an recursive manner
*/

int abs_rec(int in)
{
    if (in >= 0)
        return (in);
    else if (in != -2147483648)
        return (-in);
    else
        return (2147483647);
}

int my_compute_power_rec(int nb, int p)
{
    int prev;

    if (p < 0 || (nb == 0 && p != 0))
        return (0);
    if (p == 0)
        return (1);
    if (p == 1) {
        return (nb);
    }
    prev = my_compute_power_rec(nb, p - 1);
    if (prev > 2147483647 / abs_rec(nb))
        return (0);
    if (prev < -2147483648 / abs_rec(nb))
        return (0);
    return (nb * prev);
}
