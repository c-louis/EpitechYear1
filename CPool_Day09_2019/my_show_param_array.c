/*
** EPITECH PROJECT, 2019
** my_show_param_array
** File description:
** show info_param array
*/

int my_put_nbr(int nb);

void my_putstr(char *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab);

int my_show_param_array(struct info_param const *par)
{
    int i = 0;
    while (par[i].str != "0") {
        my_putstr(par[i].str);
        my_putchar(10);
        my_put_nbr(par[i].length);
        my_putchar(10);
        my_show_word_array(par[i].word_array);
        i++;
    }
}
