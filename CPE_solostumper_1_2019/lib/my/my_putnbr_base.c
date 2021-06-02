/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** conver dev to any base
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int base_lengh = my_strlen(base);
    int temp;
    int i = 0;
    int lenght = 0;
    char tmp_string[500];

    while (nbr != 0) {
        temp = nbr % base_lengh;
        tmp_string[i++] = base[temp];
        nbr = nbr / base_lengh;
    }
    for (int y = i - 1; y >= 0; y--) {
        my_putchar(tmp_string[y]);
        lenght++;
    }
    return (lenght);
}
