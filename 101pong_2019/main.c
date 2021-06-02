/*
** EPITECH PROJECT, 2019
** main of the 101pong
** File description:
** 101pong main
*/

#include "101pong.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void incidence_angle(vector_t *velocity, vector_t *v2, vector_t *endpos)
{
    if ((endpos->z < 0 && v2->z > 0) || (endpos->z > 0 && v2->z < 0)) {
        float polo = asinf((velocity->z)/(sqrtf(pow(velocity->x, 2)+
                                            pow(velocity->y, 2)+
                                            pow(velocity->z, 2)
                                            )));
        polo = (polo*180)/M_PI;
        if (polo < 0)
            polo = -polo;
        if (polo > 90)
            polo = 180 - polo;
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", polo);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
}

vector_t *get_endpos(vector_t *v2, vector_t *velocity, float t)
{
    vector_t *endpos = malloc(sizeof(vector_t));
    endpos->x = v2->x + (t * velocity->x);
    endpos->y = v2->y + (t * velocity->y);
    endpos->z = v2->z + (t * velocity->z);
    return (endpos);
}

vector_t *get_velocity(vector_t *v1, vector_t *v2)
{
    vector_t *velocity = malloc(sizeof(vector_t));
    velocity->x = v2->x - v1->x;
    velocity->y = v2->y - v1->y;
    velocity->z = v2->z - v1->z;
    return (velocity);
}

void print_help(void)
{
    printf("USAGE\n\t");
    printf("./101pong x0 y0 z0 x1 y1 z1 n\n\n\n\t");
    printf("DESCRIPTION\n");
    printf("\tx0  ball abscissa at time t - 1\n");
    printf("\ty0  ball ordinate at time t - 1\n");
    printf("\tz0  ball altitude at time t - 1\n");
    printf("\tx1  ball abscissa at time t\n");
    printf("\ty1  ball ordinate at time t\n");
    printf("\tz1  ball altitude at time t\n");
    printf("\tn   time shift (greater than or equal to zero, integer)\n");
}

int main(int ac, char **av)
{
    if (ac != 8) {
        if (ac < 2)
            return (84);
        if (my_strcmp(av[1], "-h") == 0) {
            print_help();
        } else {
            return (84);
        }
    } else {
        test_error(ac, av);
        vector_t v1 = {atof(av[1]), atof(av[2]), atof(av[3])};
        vector_t v2 = {atof(av[4]), atof(av[5]), atof(av[6])};
        vector_t *velocity = get_velocity(&v1, &v2);
        vector_t *end_pos = get_endpos(&v2, velocity, atof(av[7]));
        printf("The velocity vector of the ball is:\n");
        printf("(%.2f, %.2f, %.2f)\n", velocity->x, velocity->y, velocity->z);
        printf("At time t + %d, ball coordinates will be:\n", atoi(av[7]));
        printf("(%.2f, %.2f; %.2f)\n", end_pos->x, end_pos->y, end_pos->z);
        incidence_angle(velocity, &v2, end_pos);
    }
}
