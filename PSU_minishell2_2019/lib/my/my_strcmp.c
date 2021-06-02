/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare to string
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int maxS1 = my_strlen(s1);
    int maxS2 = my_strlen(s2);

    while (i < maxS1 || i < maxS2) {
        if (s1[i] != s2[i]) {
            int diff = (int) s1[i] - (int) s2[i];
            return (diff);
        }
        i++;
    }
    return (0);
}
