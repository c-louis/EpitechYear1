/*
** EPITECH PROJECT, 2019
** nmatch
** File description:
** find if string match together and how many time they match
*/

int nmatch(char const *s1, char const *s2)
{
    if (*s2 == '*' && *s1 != '\0') {
        return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
    }
    if (*s2 == '*' && *s1 == '\0') {
        return (nmatch(s1, s2 + 1));
    }
    if (*s2 == *s1 && *s1 != '\0') {
        return (nmatch(s1 + 1, s2 + 1));
    }
    if (*s1 == *s2 && *s1 == '\0') {
        return (1);
    }
    return (0);
}
