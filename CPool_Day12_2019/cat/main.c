/*
** EPITECH PROJECT, 2019
** main_file
** File description:
** description
*/

void errorz(int error, char *file);
void read_and_write(char *file);
int main_bin(int ac, char **argc);

int main(int ac, char **av)
{
    errorz(0, "directory/");
    main_bin(ac, av);
    return (0);
}
