/*
** EPITECH PROJECT, 2019
** tests_my_put_nbr
** File description:
** display the given number
*/

int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(100);
    my_put_nbr(0);
    my_put_nbr(-100);
    my_put_nbr(-2147483648);
    my_put_nbr(2147483647);
    return (0);
}
