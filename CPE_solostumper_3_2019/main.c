/*
** EPITECH PROJECT, 2020
** main fizzbuzz
** File description:
** fizzbuzz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fizzbuzz(int nb1, int nb2)
{
    for (int i = nb1; i <= nb2; i++) {
        if (i % 5 == 0 && i % 3 == 0) {
            printf("FizzBuzz\n");
            continue;
        }
        if (i % 5 == 0)
            printf("Buzz\n");
        else if (i % 3 == 0)
            printf("Fizz\n");
        else
            printf("%d\n", i);
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    int nb1 = atoi(av[1]);
    int nb2 = atoi(av[2]);

    if (nb2 < nb1) {
        write(2, "Error: the second parameter must be ", 36);
        write(2, "greater than the first one.\n", 28);
        return (84);
    }
    fizzbuzz(nb1, nb2);
    return (0);
}
