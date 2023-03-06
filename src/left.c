/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game1
*/

#include "tetris.h"

void disp6(data_t *data)
{
    if (data->y == 0|| data->y == data->game->height-1 || \
data->x == 0 || data->x == data->game->width-1)
        data->map[data->y][data->x] = '*';
}

void change2(data_t *data, global_data_t *gdata)
{
    data->y = 0;
    data->x = 0;
    data->menu = malloc(sizeof(menu_t));
    data->game = malloc(sizeof(game_t));
    data->next = malloc(sizeof(next_t));
    data->menu->width = 60;
    data->menu->height = 15;
    data->game->width = gdata->width+2;
    data->game->height = gdata->height+2;
    data->next->height = 0;
    data->next->width = 0;
    for (int i = 0; i != data->nbr_tetriminos; i++) {
        if (data->tetriminos[i]->height + 4 > data->next->height)
            data->next->height = data->tetriminos[i]->height + 4;
        if (data->tetriminos[i]->width + 4 > data->next->width)
            data->next->width = data->tetriminos[i]->width + 4;
    }
    data->width_win = data->menu->width + data->\
next->width + data->game->width+3;
}

void change3(data_t *data)
{
    if (data->game->height > data->next->height && \
data->game->height > data->menu->height)
        data->height_win = data->game->height+2;
    if (data->next->height > data->game->height && \
data->next->height > data->menu->height)
        data->height_win = data->next->height+2;
    if (data->menu->height > data->game->height && \
data->menu->height > data->next->height)
        data->height_win = data->menu->height+2;
    data->map = malloc(sizeof(char *) * (data->game->height+1));
}

void change_setting_data(data_t *data, global_data_t *gdata)
{
    change2(data, gdata);
    change3(data);
    for (data->y = 0; data->y != data->game->height; data->y ++) {
        data->map[data->y] = malloc(sizeof(char) * (data->game->width+1));
        for (data->x = 0; data->x != data->game->width; data->x ++) {
            data->map[data->y][data->x] = ' ';
            disp6(data);
        }
        data->map[data->y][data->x] = '\0';
    }
    data->map[data->y] = NULL;
}

void disp5(data_t *data)
{
    wprintw(data->menu->win, "Full Line :\n");
    wprintw(data->menu->win, "Level :\n");
    wprintw(data->menu->win, "\n");
    wprintw(data->menu->win, "Hight Score :\n");
    wprintw(data->menu->win, "Score :\n");
    wprintw(data->menu->win, "\n");
    wprintw(data->menu->win, "Time :\n");
    wborder(data->game->win, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(data->next->win, '|', '|', '-', '-', '/', '\\', '\\', '/');
    wattron(data->win, COLOR_PAIR(2));
    box(data->win, 0, 0);
    wattroff(data->win, COLOR_PAIR(2));
}
