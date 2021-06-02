/*
** EPITECH PROJECT, 2019
** lucas.decrock@epitech.eu
** File description:
** strrev
*/

char *strrev(char *str)
{
    int i = 0;
    int j = 0;
    char tempval;

    while (str[i] != '\0')
        i++;
    i = i - 1;
    while (j < i) {
        tempval = str[i];
        str[i] = str[j];
        str[j] = tempval;
        i--;
        j++;
    }
    return str;
}
