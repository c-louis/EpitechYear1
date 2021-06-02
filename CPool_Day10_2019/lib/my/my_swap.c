/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap two int
*/

void my_swap(int *a, int *b)
{
    int save_a = *a;
    int save_b = *b;

    *b = save_a;
    *a = save_b;
}
