/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** take_map_size.c
*/

#include "tetris.h"

bool take_map_size(global_data_t *gdata, char *value)
{
    int check = 0;

    if (is_num(value, ",") == false)
        return (false);
    check = search_n_occurence(value, ",", 1);
    if (search_n_occurence(value, ",", -1) != check)
        return (false);
    gdata->height = get_number(my_realloc(value, check, true, false));
    gdata->width = get_number(&(value[check + 1]));
    return (true);
}