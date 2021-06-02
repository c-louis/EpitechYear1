/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** Get every lowercase letter in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 'a' - 'A';
        }
    }
    return (str);
}
