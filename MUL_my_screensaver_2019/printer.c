/*
** EPITECH PROJECT, 2019
** printer
** File description:
** printer function
*/

#include "my.h"

void print_help(void)
{
    my_putstr("Animation rendering in a CSFML window.\n\nUSAGE:\n");
    my_putstr("\t./my_screensaver [animation_id, -h, -d]\n");
    my_putstr("\tanimation_id\tID of the animation to process");
    my_putstr(" (between 0 and 4).\n\nOPTION:\n\t");
    my_putstr("-h\t print the usage and quit.\n\t-d\t");
    my_putstr("print the description of all the animations and quit.\n");
}

void print_details(void)
{
    my_printf("0: Random line going anywhere randomly");
    my_printf("(Straight line or 'stairs line')\n");
    my_printf("1: Epileptik moving circle to the left (Many colour)\n");
    my_printf("2: White circle going to the right 'half plain'\n");
    my_printf("3: multiple circle going fast with random color !\n");
    my_printf("4: bi-color static random circle \n");
}
