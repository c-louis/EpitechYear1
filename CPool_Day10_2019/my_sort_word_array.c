/*
** EPITECH PROJECT, 2019
** my_sort_word_array
** File description:
** sort the word in an array
*/

int my_sort_word_array(char **tab)
{
    int i = 0;
    int sorted = 0;
    char *save_word;
    while (tab[i] != 0) {
        i++;
    }
    for (int j = 0; j < i ; j++) {
        for (int k = 0; k < i ; k++) {
            if (my_strcmp(tab[j], tab[k]) < 0) {
                save_word = tab[k];
                tab[k] = tab[j];
                tab[j] = save_word;
            }
        }
    }
    return (0);
}
