/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game6
*/

#include "tetris.h"

int move8(data_t *data)
{
    for (data->x = data->pos_tetri_x, data->x2 = 0; data\
->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
        if (move7(data) == 69)
            return (69);
    return (0);
}

void move_left(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y \
!= data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        if (move8(data) == 69)
            return;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y \
!= data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data\
->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            move6(data);
    data->pos_tetri_x--;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y \
!= data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data\
->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            move5(data);
    move9(data);
}

void remove_space(data_t *data)
{
    for (data->y = 0; data->y != data->tetri->height; data->y++)
        for (data->x = data->tetri->width; data->tetri->\
tetri[data->y][data->x] != '*'; data->x--)
            data->tetri->tetri[data->y][data->x] = '\0';
}

void move2(data_t *data)
{
    if (data->tetri->tetri[data->y2][data->x2] != ' ')
        data->map[data->y][data->x] = data->tetri->tetri[data->y2][data->x2];
}

int move3(data_t *data)
{
    if ((data->y2 == data->tetri->height-1 && data->tetri->\
tetri[data->y2][data->x2] == '*') || (data->tetri->tetri\
[data->y2][data->x2] == '*' && data->tetri->tetri\
[data->y2+1][data->x2] == ' '))
        if (data->map[data->y+1][data->x] == '*') {
            data->can_move = 0;
            return (69);
        }
    return (0);
}
