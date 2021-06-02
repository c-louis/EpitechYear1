/*
** EPITECH PROJECT, 2019
** bonus_match
** File description:
** find if string match together explaination bonus
*/

#include "my.h"
#include "bonus.h"

int MATCH_ITERATION;
int NMATCH_ITERATION;

int match(char const *s1, char const *s2)
{
    MATCH_ITERATION++;
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

int nmatch(char const *s1, char const *s2)
{
    NMATCH_ITERATION++;
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

int main(int argc, char **argv)
{
    if (argc > 2) {
        explain_match(argv);
        interlude();
        explain_nmatch(argv);
    }
    else {
        my_putstr("Veuillez entrer minimum deux arguments !\n");
    }
    return (0);
}
