/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game5
*/


#include "tetris.h"

void move13(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            data->map[data->y][data->x] = data->tetri->tetri\
[data->y2][data->x2];
}

void move_right(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        if (move12(data) == 69)
            return;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            move6(data);
    data->pos_tetri_x++;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            move10(data);
    move13(data);
}

void move5(data_t *data)
{
    if (data->map[data->y][data->x] == '*')
        data->pos_tetri_x++;
}

int move7(data_t *data)
{
    if (data->pos_tetri_x == 1)
        if (data->map[data->y][data->x-1] != ' ')
            return (69);
    return (0);
}

void move9(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            data->map[data->y][data->x] = data->tetri->tetri\
[data->y2][data->x2];
}