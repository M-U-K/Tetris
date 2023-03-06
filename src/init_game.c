/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game9
*/

#include "tetris.h"

void game4(data_t *data)
{
    if ((data->c == 410 || data->c == 0) && (\
data->width_win+1 < COLS && data->height_win+1 < LINES)) {
        clear();
        werase(data->win);
        werase(data->menu->win);
        werase(data->game->win);
        werase(data->next->win);
        delwin(data->game->win);
        delwin(data->next->win);
        delwin(data->menu->win);
        delwin(data->win);
        data->win = newwin(data->height_win, data->width_win, 0, 0);
        data->menu->win = newwin(data->menu->height, data->menu->width, 1, 1);
        data->game->win = newwin(data->game->height, \
data->game->width, 1, data->menu->width +1);
        data->next->win = newwin(data->next->height, \
data->next->width, 1, data->menu->width + data->game->width +2);
    }
}

void game5(data_t *data, global_data_t *gdata)
{
    if (data->can_move == 0) {
        data->actual_tetri = data->next_tetri;
        data->next_tetri = chose_tetriminos(data);
        data->pos_tetri_x = 1;
        data->pos_tetri_y = 1;
        data->can_move = 1;
        set_tetri(data);
        set_next_tetri(data);
        remove_space(data);
        disp_tetriminos_end(data);
        wclear(data->next->win);
    }
    if (data->c == gdata->key_right && data->tmp == 0) {
        move_right(data);
        remove_space(data);
    }
}

void game6(data_t *data, global_data_t *gdata)
{
    if (data->c == gdata->key_left && data->tmp == 0) {
        move_left(data);
        remove_space(data);
    }
    if (data->c == gdata->key_drop && data->tmp == 0) {
        while (data->can_move == 1) {
            move_down(data);
            remove_space(data);
        }
    }
    if (data->c == gdata->key_turn && data->tmp == 0) {
        data->tetri->tetri = turn_tetri(data);
        remove_space(data);
        disp_tetriminos(data);
    }
}

void game71(data_t *data)
{
    if (data->time_mili >= 1000/data->level) {
        remove_space(data);
        move_down(data);
        data->time_mili = 0;
        data->start_mili = clock();
    }
}

void game7(data_t *data)
{
    game71(data);
    find_line(data);
    wmove(data->game->win, 0, 0);
    wattron(data->game->win, COLOR_PAIR(data->tetri->color));
    for (data->y = 0; data->y != data->game->height; data->y ++) {
        wprintw(data->game->win, data->map[data->y]);
    }
    wattroff(data->next->win, COLOR_PAIR(data->tetri->color));
    wmove(data->next->win, 2, 2);
    wattron(data->next->win, COLOR_PAIR(data->next_tetri2->color));
    for (data->y = 0; data->y != data->next_tetri2->height; data->y ++) {
        wmove(data->next->win, 2+data->y, 2);
        for (data->x = 0; data->x != data->next_tetri2->width; data->x ++)
            wprintw(data->next->win, "%c", \
data->next_tetri2->tetri[data->y][data->x]);
    }
}
