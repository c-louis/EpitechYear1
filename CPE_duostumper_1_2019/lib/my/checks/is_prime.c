/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** is_prime
*/

int is_prime(int const nb)
{
    int prime = 2;

    if (nb < 2)
        return 0;
    while ((prime * prime > 0) && (prime * prime <= nb)) {
        if (nb % prime == 0)
            return 0;
        prime++;
    }
    return 1;
}