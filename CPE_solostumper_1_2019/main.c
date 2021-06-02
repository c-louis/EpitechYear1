/*
** EPITECH PROJECT, 2020
** countwords
** File description:
** count the occurencs of each word
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "my.h"
#include "countwords.h"

int word_exist(char *word, char_oc_t **word_list)
{
    char_oc_t *tmp = *word_list;
    while (tmp != NULL) {
        if (my_strcmp(tmp->word, word) == 0) {
            tmp->num = tmp->num + 1;
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void display_result(char_oc_t *occurences)
{
    char_oc_t *tmp = occurences;
    while (tmp != NULL) {
        printf("%s: %d\n", tmp->word, tmp->num);
        tmp = tmp->next;
    }
}

void free_words(char **words)
{
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}

int main(int ac, char **av)
{
    char_oc_t *occurences = NULL;

    if (ac == 1) {
        printf("\n");
        return (0);
    }
    char **all_words = my_str_to_word_array(av[1]);
    for (int i = 0; all_words[i] != NULL; i++) {
        if (word_exist(all_words[i], &occurences) == 1)
            continue;
        char_oc_t *new_word = create_node(all_words[i]);
        if (new_word == NULL)
            return (84);
        add_node_end(&occurences, new_word);
        continue;
    }
    display_result(occurences);
    free_nodes(occurences);
    free_words(all_words);
    return (0);
}
