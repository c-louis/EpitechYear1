/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** upcase all the first carac of words following some rules
*/

int is_letter(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}

int is_separator(char c)
{
    if (c == ' ' || c == '+' || c == '-')
        return (1);
    return (0);
}

void to_uppercase(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
}

void to_lowercase(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 && is_letter(str[i])) {
            to_uppercase(str, i);
        }
        else if (i != 0 && is_letter(str[i]) && is_separator(str[i - 1])) {
            to_uppercase(str, i);
        }
        else if (is_letter(str[i])) {
            to_lowercase(str, i);
        }
        i++;
    }
    return (str);
}
