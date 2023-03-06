/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game7
*/

#include "tetris.h"

int move4(data_t *data)
{
    for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
        if (move3(data) == 69)
            return (69);
    return (0);
}

void move_down(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        if (move4(data) == 69)
            return;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            data->map[data->y][data->x] = ' ';
    data->pos_tetri_y++;
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y \
!= data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++)
        for (data->x = data->pos_tetri_x, data->x2 = 0; \
data->tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++)
            move2(data);
}

void set_tetri(data_t *data)
{
    data->y = 0;
    data->x = 0;
    data->tetri = malloc(sizeof(tetri_t));
    data->tetri->width = data->tetriminos[data->actual_tetri]->width;
    data->tetri->height = data->tetriminos[data->actual_tetri]->height;
    data->tetri->color = data->tetriminos[data->actual_tetri]->color;
    data->tetri->tetri = malloc(sizeof(char *) * (data->tetri->height+1));
    for (data->y = 0; data->y != data->tetri->height; data->y++) {
        data->tetri->tetri[data->y] = malloc(sizeof(char) * \
(data->tetri->width+1));
        for (data->x = 0; data->x != data->tetri->width; data->x++) {
            data->tetri->tetri[data->y][data->x] = \
data->tetriminos[data->actual_tetri]->tetri[data->y][data->x];
        }
        data->tetri->tetri[data->y][data->x] = '\0';
    }
    data->tetri->tetri[data->y] = NULL;
}

void set_next_tetri(data_t *data)
{
    data->y = 0;
    data->x = 0;
    data->next_tetri2 = malloc(sizeof(tetri_t));
    data->next_tetri2->width = data->tetriminos[data->next_tetri]->width;
    data->next_tetri2->height = data->tetriminos[data->next_tetri]->height;
    data->next_tetri2->color = data->tetriminos[data->next_tetri]->color;
    data->next_tetri2->tetri = malloc(sizeof\
(char *) * (data->next_tetri2->height+1));
    for (data->y = 0; data->y != data->next_tetri2->height; data->y++) {
        data->next_tetri2->tetri[data->y] = malloc\
(sizeof(char) * (data->next_tetri2->width+1));
        for (data->x = 0; data->x != data->next_tetri2->width; data->x++) {
            data->next_tetri2->tetri[data->y][data->x] = \
data->tetriminos[data->next_tetri]->tetri[data->y][data->x];
        }
        data->next_tetri2->tetri[data->y][data->x] = '\0';
    }
    data->next_tetri2->tetri[data->y] = NULL;
}

int all_line(char *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] != '*')
            return (1);
    }
    return (0);
}
