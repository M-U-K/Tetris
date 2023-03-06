/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"

int main(int ac, char **av)
{
    int check = 0;
    global_data_t *gdata = init();

    gdata->binary_name = av[0];
    check = check_parameters(gdata, ac, av);
    if (check == -1)
        return (84);
    else if (check == 1)
        return (0);
    if (gdata->debug == true)
        debug(gdata);
    game(gdata);
    return (0);
}