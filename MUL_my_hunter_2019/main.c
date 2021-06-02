/*
** EPITECH PROJECT, 2019
** main file
** File description:
** main file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "menu.h"
#include "graph.h"

void show_help(void)
{
    my_printf("################### My_Hunter ###################"); 
    my_printf("\nTo play just type ./my_hunter without arguments\n");
    my_printf("To Kill pigeon click on them\n\tIf you need to pee");
    my_printf(" or poo just press Escape to pause the game\n");
    my_printf("The game is infinite don't try to finish it !");
    my_printf(" (You will die before the game)\n");
    my_printf("Every 4 bullet you are reloading ! (Automatically)\n");
    my_printf("You're score is at the bottom-left-corner !\n");
    my_printf("##################### ENJOY #####################\n");
    my_printf("################### My_Hunter ###################\n");
}

void show_game(void)
{
    sfRenderWindow *window;
    sfEvent *event = malloc(sizeof(sfEvent));
    sfVideoMode mode = {1600, 1000, 32};
    glg_t *gl = malloc(sizeof(glg_t));
    init_global(gl);
    window = sfRenderWindow_create(mode, "Pigeon-Shooter", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    gl->window = window;
    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, event)) {
            process_event(window, event, gl);
        }
        main_loop(window, gl);
    }
    clean_all(gl);
    sfRenderWindow_destroy(window);
    free(event);
}

int main(int ac, char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0)
            show_help();
        else {
            my_printf("Argument : %s inconnu !\n", av[1]);
            return (84);
        }
    } else {
        show_game();
    }
    return (0);
}
