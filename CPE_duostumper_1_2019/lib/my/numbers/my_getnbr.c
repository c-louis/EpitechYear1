/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int count_minus = 0;
    int check_my_overflow;
    while (str[i] == '-' || str [i] == '+') {
        if (str[i] == '-')
            count_minus++;
    i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        check_my_overflow = number;
        number = number * 10 + str[i] - '0';
        if (number / 10 != check_my_overflow && number != -2147483648)
            return (0);
        if (number == 214748364 && str[i + 1] == '8' && count_minus % 2 == 0)
            return (0);
        i++;
    }
    return (count_minus % 2 != 0 ? -number : number);
}