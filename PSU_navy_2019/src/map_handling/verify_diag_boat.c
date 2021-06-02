/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** verify_diag_boat
*/

int verify_diag_boat(char *data_line)
{
    if (data_line[3] != data_line[6]) {
        if (data_line[2] == data_line[5])
            return (0);
    } else if (data_line[2] != data_line[5])
        if (data_line[3] == data_line[6])
            return (0);
    return (84);
}