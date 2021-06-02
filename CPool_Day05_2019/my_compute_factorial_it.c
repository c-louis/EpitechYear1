/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** factorial with iterative loop
*/

int my_compute_factorial_it(int nb)
{
    int factorial = nb;

    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    if (nb > 12)
        return (0);
    while (nb > 1) {
        factorial = factorial * (nb - 1);
        nb--;
    }
    return (factorial);
}
