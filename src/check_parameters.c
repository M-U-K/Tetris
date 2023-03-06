/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_parameters.c
*/

#include "tetris.h"

const struct option long_options[] = {
    {"help", no_argument, NULL, 0},
    {"level", required_argument, NULL, 0},
    {"key-left", required_argument, NULL, 0},
    {"key-right", required_argument, NULL, 0},
    {"key-turn", required_argument, NULL, 0},
    {"key-drop", required_argument, NULL, 0},
    {"key-quit", required_argument, NULL, 0},
    {"key-pause", required_argument, NULL, 0},
    {"map-size", required_argument, NULL, 0},
    {"without-next", no_argument, NULL, 0},
    {"debug", no_argument, NULL, 0},
    {NULL, 0, NULL, 0}
};

void case_h(char *binary_name)
{
    my_printf("Usage:\t%s [options]\n", binary_name);
    my_printf("Options:\n");
    my_printf("  --help\t\tDisplay this help\n");
    my_printf("  -L --level={num}\tStart Tetris at level num (def: 1)\n");
    my_printf("  -l --key-left={K}\tMove the tetrimino LEFT using the K key"
    " (def: left arrow)\n");
    my_printf("  -r --key-right={K}\tMove the tetrimino RIGHT using the K"
    " key (def: right arrow)\n");
    my_printf("  -t --key-turn={K}\tTURN the tetrimino clockwise 90d using "
    "the K key (def: top arrow)\n");
    my_printf("  -d --key-drop={K}\tDROP the tetrimino using the K key (def:"
    " down arrow)\n");
    my_printf("  -q --key-quit={K}\tQUIT the game using the K key (def: "
    "‘q’ key)\n");
    my_printf("  -p --key-pause={K}\tPAUSE/RESTART the game using the K "
    "key (def: space bar)\n");
    my_printf("  --map-size={row,col}\tSet the numbers of rows and columns"
    " of the map (def: 20,10)\n");
    my_printf("  -w --without-next\tHide next tetrimino (def: false)\n");
    my_printf("  -D --debug\t\tDebug mode (def: false)\n");
}

int take_param(global_data_t *gdata, int index, char *value)
{
    int check = 0;

    check = take_param_first(gdata, index, value);
    if (check != 0)
        return (check);
    check = take_param_second(gdata, index, value);
    if (check != 0)
        return (check);
    check = take_param_third(gdata, index, value);
    if (check != 0)
        return (check);
    check = take_param_fourth(gdata, index, value);
    if (check != 0)
        return (check);
    check = take_param_fifth(gdata, index, value);
    if (check != 0)
        return (check);
    return (0);
}

int check_parameters(global_data_t *gdata, int ac, char **av)
{
    int check = 0;
    int option_index = 0;

    while ((check = getopt_long(ac, av, "+L:l:r:t:d:q:p:wD",
    long_options, &option_index)) != -1) {
        switch (check) {
        case '?':
            return (-1);
        case 0:
            check = take_param(gdata, option_index, optarg);
            break;
        default:
            check = take_param(gdata, check, optarg);
            break;
        }
        if (check != 0)
            return (check);
    }
    return (0);
}