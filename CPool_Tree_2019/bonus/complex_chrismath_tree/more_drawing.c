/*
** EPITECH PROJECT, 2019
** complex_chrismath_tree_additionnal_drawing
** File description:
** additionnal drawing for the complex chrismath tree
*/

void draw_star(int n, int initial_space)
{
    write(1, "\x1b[33m", 6);
    for (int i = 0; i < initial_space; i++) {
        my_putchar(' ');
    }
    my_putchar('*');
    my_putchar('\n');
}
