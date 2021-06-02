/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Reproduce the behavior of the func
*/

int my_strcmp(const char *s1, const char *s2)
{
    int total = 0;
    for (int i = 0; s1[i] != '\0'; i++){
        total += s1[i];
    }
    for (int i = 0; s2[i] != '\0'; i++){
        total -= s2[i];
    }
    return (total);
}
