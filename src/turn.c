/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game4
*/

#include "tetris.h"

char ** turn_tetri(data_t *data)
{
    int height = data->tetri->width;
    int width = data->tetri->height;
    char **tetri = malloc(sizeof(char *) * (data->tetri->width+1));

    if (data->tetri->width+data->pos_tetri_y > data->game->height-1)
        return (data->tetri->tetri);
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            turn2(data);
    for (data->y = data->pos_tetri_y; data->y != data->tetri->\
width+data->pos_tetri_y; data->y ++)
        if (turn4(data) == 69)
            return (data->tetri->tetri);
    turn5(data, tetri, height, width);
    return (tetri);
}

void move10(data_t *data)
{
    if (data->map[data->y][data->x] == '*')
        data->pos_tetri_x--;
}

void move6(data_t *data)
{
    if (data->tetri->tetri[data->y2][data->x2] == '*')
        data->map[data->y][data->x] = ' ';
}

int move11(data_t *data)
{
    if (data->tetri->tetri[data->y2][data->x2+1] == '\0' && \
data->tetri->tetri[data->y2][data->x2] == '*')
        if (data->map[data->y][data->x+1] != ' ')
            return (69);
    return (0);
}

int move12(data_t *data)
{
    for (data->x = data->pos_tetri_x, data->x2 = 0; \
data->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
        if (move11(data) == 69)
            return (69);
    return (0);
}

