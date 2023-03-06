/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_key.c
*/

#include "tetris.h"

bool check_key(char *value)
{
    if (is_alpha_low(value, " ABCD") == true\
&& string_len(value, '\0') == 1)
        return (true);
    return (false);
}