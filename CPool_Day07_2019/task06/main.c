/*
** EPITECH PROJECT, 2019
** print_params_man
** File description:
** main for the my_print 
*/

void my_sort_params(int argc, char **argv);

int main(int argc, char **argv)
{
    if (argc > 0)
        my_sort_params(argc, argv);
    return (0);
}
