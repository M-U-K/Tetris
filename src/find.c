/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game8
*/

#include "tetris.h"

void find_line3(data_t *data)
{
    if (data->map[data->y][data->x] == '*' && \
data->map[data->y+1][data->x] != '*') {
        data->map[data->y][data->x] = ' ';
        data->map[data->y+1][data->x] = '*';
    }
}

void find_line2(data_t *data)
{
    data->ligne ++;
    data->score += 100;
    data->boost_lvl++;
    if (data->boost_lvl >= 10) {
        data->level++;
        data->boost_lvl = 0;
    }
    for (data->x = 1; data->x != data->game->width-1; data->x++)
        data->map[data->y][data->x] = ' ';
    for (data->y = data->game->height-2; data->y != 0; data->y--) {
        for (data->x = data->game->width-2; data->x != 0; data->x--) {
            find_line3(data);
        }
    }
}

void find_line(data_t *data)
{
    for (data->y = 1; data->y != data->game->height-1; data->y++) {
        if (all_line(data->map[data->y]) == 0) {
            find_line2(data);
        }
    }
}

void game2(global_data_t *gdata, data_t *data)
{
    data->c = 0;
    data->tmp = 0;
    data->touche = 0;
    srand(time(NULL));
    change_setting_data(data, gdata);
    if (data->can_start == 0) {
        print_string("Folder tetriminos doesn't exist");
        exit(84);
    }
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    clear();
    nodelay(stdscr, true);
    start_color();
}

void game3(void)
{
    init_pair(0, 0, COLOR_BLACK);
    init_pair(1, 1, COLOR_BLACK);
    init_pair(2, 2, COLOR_BLACK);
    init_pair(3, 3, COLOR_BLACK);
    init_pair(4, 4, COLOR_BLACK);
    init_pair(5, 5, COLOR_BLACK);
    init_pair(6, 6, COLOR_BLACK);
    init_pair(7, 7, COLOR_BLACK);
    init_pair(8, 8, COLOR_BLACK);
    init_pair(9, 9, COLOR_BLACK);
    init_pair(10, 10, COLOR_BLACK);
    init_pair(11, 11, COLOR_BLACK);
    init_pair(12, 12, COLOR_BLACK);
    init_pair(13, 13, COLOR_BLACK);
    init_pair(14, 14, COLOR_BLACK);
    init_pair(15, 15, COLOR_BLACK);
}
