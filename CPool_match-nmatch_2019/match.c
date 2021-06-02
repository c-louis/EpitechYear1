/*
** EPITECH PROJECT, 2019
** match
** File description:
** find if string match together
*/

int match(char const *s1, char const *s2)
{
    if (*s2 == '*' && *s1 != '\0') {
        return (match(s1 + 1, s2) || match(s1, s2 + 1));
    }
    if (*s2 == '*' && *s1 == '\0') {
        return (match(s1, s2 + 1));
    }
    if (*s2 == *s1 && *s1 != '\0') {
        return (match(s1 + 1, s2 + 1));
    }
    if (*s1 == *s2 && *s1 == '\0') {
        return (1);
    }
    return (0);
}
