/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game3
*/

#include "tetris.h"

void disp_tetriminos_end(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y \
!= data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; \
data->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            disp3(data);
}

void turn2(data_t *data)
{
    if (data->tetri->tetri[data->y2][data->x2] == '*')
        data->map[data->y][data->x] = ' ';
}

char **turn3(data_t *data, char **tetri)
{
    if (data->tetri->tetri[data->y][data->x] == 0)
        tetri[data->y2][data->x2] = ' ';
    return (tetri);
}

int turn4(data_t *data)
{
    for (data->x = data->pos_tetri_x; data->x != \
data->tetri->height+data->pos_tetri_x; data->x++)
        if (data->map[data->y][data->x] == '*' && \
data->x != data->game->width-1)
            return (69);
    return (0);
}

void turn5(data_t *data, char **tetri, int height, int width)
{
    for (data->x = 0; data->x != data->tetri->width; data->x++)
        tetri[data->x] = malloc(sizeof(char) * (data->tetri->height+1));
    for (data->x = 0, data->y2 = 0; data->x != data->tetri->\
width; data->x++, data->y2++) {
        for (data->y = data->tetri->height-1, data->x2 = 0; \
data->y != -1; data->y--, data->x2++) {
            tetri[data->y2][data->x2] = data->tetri->tetri[data->y][data->x];
            tetri = turn3(data, tetri);
        }
        tetri[data->y2][width] = '\0';
    }
    data->tetri->height = height;
    data->tetri->width = width;
    while (data->tetri->width + data->pos_tetri_x > data->game->width-1)
        data->pos_tetri_x --;
}
