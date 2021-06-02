/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_get_nbr fictive
*/

int check_limit(char const *str, char *limit, int start)
{
    for (int i = 0; i < 10; i++) {
        if (str[start + i] > limit[i])
            return (1);
    }
    return (0);
}

int is_forbid(char const *str, int start, int is_neg)
{
    int end = start;
    int length = 0;
    char *pos = "2147483647";
    char *neg = "2147483648";
    for (end; str[end] >= '0' && str[end] <= '9'; end++) {
        length++;
    }
    if (length > 10)
        return (1);
    if (length == 10 && is_neg == -1) {
        if (check_limit(str, neg, start))
            return (1);
    }
    if (length == 10 && is_neg == 1) {
        if (check_limit(str, pos, start))
            return (1);
    }
    return (0);
}

int get_number(char const *str, int i)
{
    int n = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        n = (n * 10) + (str[i] - 48);
        i++;
    }
    return (n);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int is_neg = 1;
    int length = 0;
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            is_neg = is_neg * -1;
        }
        i++;
    }
    if (is_forbid(str, i, is_neg))
        return (0);
    return (get_number(str, i) * is_neg);
}
