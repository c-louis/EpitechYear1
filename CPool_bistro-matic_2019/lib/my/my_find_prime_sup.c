/*
** EPITECH PROJECT, 2019
** my_prime_find_sup
** File description:
** Find the smallest, sup or eq to prime number from input
*/

int my_is_prime_finder(int nb)
{
    if (nb < 2)
        return (0);
    for (int i = 2; i * i <= nb; i++){
        if (nb % i == 0 && i != nb)
            return (0);
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    for (; my_is_prime_finder(i) != 1; i++);
    return (i);
}
