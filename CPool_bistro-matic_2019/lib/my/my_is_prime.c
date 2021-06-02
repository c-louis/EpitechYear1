/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Check if input is prime,
** returns 1 if it is and 0 if not
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    for (int i = 2; i * i <= nb; i++){
        if (nb % i == 0 && i != nb)
            return (0);
    }
    return (1);
}
