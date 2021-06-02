/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** check if str is only alphabetical
*/

int is_letter(char c);

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (!(is_letter(str[i]))) {
            return (0);
        }
        i++;
    }
    return (1);
}
