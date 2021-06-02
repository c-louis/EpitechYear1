/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** iterative power func
*/

int my_compute_power_it(int nb, int p)
{
    int original_nb = nb;

    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    if (p < 0)
        return (0);
    while (p >= 2) {
        nb = nb * original_nb;
        p--;
    }
    return (nb);
}
