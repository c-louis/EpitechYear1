/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** recursive power function
*/

int my_compute_power_rec(int nb, int p)
{
    int rec = nb;

    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    if (p < 0)
        return (0);
    rec = nb * my_compute_power_rec(nb, p-1);
    return (rec);
}
