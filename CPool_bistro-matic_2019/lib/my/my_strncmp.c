/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Reproduce the behavior of the func
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    int total = 0;
    for (int i = 0; i < n && s1[i] != '\0'; i++){
        total += s1[i];
    }
    for (int i = 0; i < n && s2[i] != '\0'; i++){
        total -= s2[i];
    }
    return (total);
}
