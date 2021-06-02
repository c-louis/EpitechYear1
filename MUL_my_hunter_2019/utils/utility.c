/*
** EPITECH PROJECT, 2019
** utility
** File description:
** utility function for the my hunter
*/

static unsigned int rand_state;

unsigned int my_rand(void)
{
    rand_state = ((rand_state * 22695477 + 1) % 0x7fffffff);
    return rand_state;
}
