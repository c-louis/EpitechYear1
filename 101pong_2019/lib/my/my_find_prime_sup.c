/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** todo
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return (nb);
    while (!my_is_prime(nb))
        nb++;
    return (nb);
}
