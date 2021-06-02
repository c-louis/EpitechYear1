/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** factorial using recursive functio,
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    if (nb > 12)
        return (0);
    return (nb * my_compute_factorial_rec(nb -1));
}
