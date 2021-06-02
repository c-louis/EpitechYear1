/*
** EPITECH PROJECT, 2019
** explication_match
** File description:
** function to explain difference between match && nmatch
*/

#include "my.h"
#include "bonus.h"

extern int NMATCH_ITERATION;
extern int MATCH_ITERATION;

void explain_match(char **argv)
{
    my_putstr("Resultat d'un simple Match : \n");
    my_putstr("Le Resultat est : ");
    my_put_nbr(match(argv[1], argv[2]));
    my_putchar(10);
    my_putstr("Il aura fallu : \x1b[31m");
    my_put_nbr(MATCH_ITERATION);
    my_putstr("\x1b[0m appel de la fonction Match pour avoir le résultat");
}

void interlude(void)
{
    my_putstr("\n\n\x1b[32mEt pour un nmatch ?? \x1b[0m\n\n");
}

void explain_nmatch(char **argv)
{
    my_putstr("Resultat d'un N Match : \n");
    my_putstr("Le Resultat est : ");
    my_put_nbr(nmatch(argv[1], argv[2]));
    my_putchar(10);
    my_putstr("Il aura fallu : \x1b[31m");
    my_put_nbr(NMATCH_ITERATION);
    my_putstr("\x1b[0m appel de la fonction NMatch pour avoir le résultat\n");
}
