/*
** EPITECH PROJECT, 2019
** tree
** File description:
** display an ascii tree
*/

void draw_logs(int n, int max_carac)
{

    int height = n;
    int weight = n;
    int space = (max_carac - n) / 2;

    write(1, "\x1b[33m", 6);
    if (n % 2 == 0)
        weight = n + 1;
    for (int i = 0; i < height; i++) {
        for (int y = 0; y < space; y++)
            my_putchar(' ');
        for (int z = 0; z < weight; z++)
            my_putchar('|');
        my_putchar('\n');
    }
    write(1, "\x1b[0m", 5);
}

void draw_line(int spacer, int leaf)
{
    for (int i = 0; i < spacer; i++)
    {
        my_putchar(' ');
    }
    for (int i = 0; i < leaf; i++)
    {
        if (i % 2 == 0)
            write(1, "\x1b[32m", 5);
        else
            write(1, "\x1b[31m", 5);
        my_putchar('*');
    }
    my_putchar('\n');
}

void draw_layers(int number_of_layer, int max_carac)
{
    int start_space = max_carac / 2;
    int leaf = 1;
    int layer_height = 3;
    int add_space = 2;
    int delete_leaf = 4;

    for (int i = 1; i < number_of_layer + 1; i++) {
        for (int y = 0; y < layer_height + i; y++) {
            draw_line(start_space, leaf);
            leaf += 2;
            start_space -= 1;
        }
        leaf -= delete_leaf;
        start_space += add_space;
        if (i >= 2 && i % 2 == 0) {
            delete_leaf += 2;
            add_space += 1;
        }
    }
}

void tree(int n)
{
    if (n <= 0)
        return;
    int max_carac = 7;
    int add_carac = 6;
    for (int i = 1; i < n; i++) {
        max_carac += add_carac;
        if (i % 2 == 1)
            add_carac += 2;
    }
    draw_layers(n, max_carac);
    draw_logs(n, max_carac);
}
