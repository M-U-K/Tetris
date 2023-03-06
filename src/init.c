/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init.c
*/

#include "tetris.h"

global_data_t *init(void)
{
    global_data_t *gdata = malloc(sizeof(global_data_t));

    gdata->level = 1;
    gdata->key_left = 68;
    gdata->key_right = 67;
    gdata->key_turn = 65;
    gdata->key_drop = 66;
    gdata->key_quit = 'q';
    gdata->key_pause = ' ';
    gdata->height = 20;
    gdata->width = 10;
    gdata->without_next = false;
    gdata->debug = false;
    return (gdata);
}