/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Capitalize the first letter of each word
*/

int is_upcase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int is_lowcase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int is_waiting_word = 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (is_waiting_word == 0 && is_upcase(str[i]) == 1){
            str[i] += 'a' - 'A';
        }
        if (is_waiting_word == 1){
            if (is_lowcase(str[i]) == 1)
                str[i] -= 'a' - 'A';
            if (is_lowcase(str[i]) == 1 || is_upcase(str[i]) == 1
                || (str[i] >= '0' && str[i] <= '9'))
                is_waiting_word = 0;
        }
        if (is_upcase(str[i]) == 0 && is_lowcase(str[i]) == 0
            && !(str[i] >= '0' && str[i] <= '9'))
            is_waiting_word = 1;
    }
    return (str);
}
