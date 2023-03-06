/*
** EPITECH PROJECT, 2019
** Tetris_2019
** File description:
** take_parameters.c
*/

#include "tetris.h"

int take_param_first(global_data_t *gdata, int index, char *value)
{
    switch (index) {
    case 0:
        return (case_h(gdata->binary_name), 1);
    case 1:
        if (is_a_number(value) == true && get_number(value) > 0)
            return (gdata->level = get_number(value), 0);
        return (print_error("Error: Invalid level value\n"), -1);
    case 2:
        if (check_key(value) == true)
            return (gdata->key_left = value[0], 0);
        return (print_error("Error: Invalid left key given\n"), -1);
    case 3:
        if (check_key(value) == true)
            return (gdata->key_right = value[0], 0);
        return (print_error("Error: Invalid right key given\n"), -1);
    }
    return (0);
}

int take_param_second(global_data_t *gdata, int index, char *value)
{
    switch (index) {
    case 4:
        if (check_key(value) == true)
            return (gdata->key_turn = value[0], 0);
        return (print_error("Error: Invalid turn key given\n"), -1);
    case 5:
        if (check_key(value) == true)
            return (gdata->key_drop = value[0], 0);
        return (print_error("Error: Invalid drop key given\n"), -1);
    case 6:
        if (check_key(value) == true)
            return (gdata->key_quit = value[0], 0);
        return (print_error("Error: Invalid quit key given\n"), -1);
    case 7:
        if (check_key(value) == true)
            return (gdata->key_pause = value[0], 0);
        return (print_error("Error: Invalid pause key given\n"), -1);
    }
    return (0);
}

int take_param_third(global_data_t *gdata, int index, char *value)
{
    switch (index) {
    case 8:
        if (take_map_size(gdata, value) == true)
            return (0);
        return (print_error("Error: Invalid map size given\n"), -1);
    case 9:
        return (gdata->without_next = true, 0);
    case 10:
        return (gdata->debug = true, 0);
    case 'L':
        if (is_a_number(value) == true && get_number(value) > 0)
            return (gdata->level = get_number(value), 0);
        return (print_error("Error: Invalid level value\n"), -1);
    case 'l':
        if (check_key(value) == true)
            return (gdata->key_left = value[0], 0);
        return (print_error("Error: Invalid left key given\n"), -1);
    }
    return (0);
}

int take_param_fourth(global_data_t *gdata, int index, char *value)
{
    switch (index) {
    case 'r':
        if (check_key(value) == true)
            return (gdata->key_right = value[0], 0);
        return (print_error("Error: Invalid right key given\n"), -1);
    case 't':
        if (check_key(value) == true)
            return (gdata->key_turn = value[0], 0);
        return (print_error("Error: Invalid turn key given\n"), -1);
    case 'd':
        if (check_key(value) == true)
            return (gdata->key_drop = value[0], 0);
        return (print_error("Error: Invalid drop key given\n"), -1);
    case 'q':
        if (check_key(value) == true)
            return (gdata->key_quit = value[0], 0);
        return (print_error("Error: Invalid quit key given\n"), -1);
    }
    return (0);
}

int take_param_fifth(global_data_t *gdata, int index, char *value)
{
    switch (index) {
    case 'p':
        if (check_key(value) == true)
            return (gdata->key_pause = value[0], 0);
        return (print_error("Error: Invalid pause key given\n"), -1);
    case 'w':
        return (gdata->without_next = true, 0);
    case 'D':
        return (gdata->debug = true, 0);
    }
    return (0);
}