/*
** EPITECH PROJECT, 2019
** get_color
** File description:
** get int color from 3 unsigned char
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = (red << 16) | (green << 8) | blue;
    return (color);
}
