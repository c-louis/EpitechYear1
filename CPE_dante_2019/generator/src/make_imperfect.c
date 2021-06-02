/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** make_imperfect
*/

int make_imperfect(char **maze, int width, int height)
{
    int breaker = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = (breaker % 10 == 0) ? '*' : maze[i][j];
            breaker++;
        }
    }
    return (1);
}