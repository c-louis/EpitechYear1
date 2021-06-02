/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare to string but limit to n caracter
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 0)
        return (my_strcmp(s1, s2));
    if (n == 0)
        return (0);
    while (i < n) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        if (s1[i] != s2[i]) {
            int diff = (int) s1[i] - (int) s2[i];
            return (diff);
        }
        i++;
    }
    return (0);
}
