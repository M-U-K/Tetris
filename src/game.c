/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include "tetris.h"


void game8(data_t *data)
{
    wattroff(data->next->win, COLOR_PAIR(data->next_tetri2->color));
    if (data->tmp == 1) {
        wmove(data->menu->win, 10, 30);
        wattrset(data->menu->win, A_BOLD);
        wprintw(data->menu->win, "PAUSE");
        wstandend(data->menu->win);
    }
    refresh();
    data->actual = clock();
    data->time = (data->actual - data->start) / CLOCKS_PER_SEC;
    data->time_mili = (data->actual - data->start_mili) * 1000 / CLOCKS_PER_SEC;
    wmove(data->menu->win, 7, 12);
    wprintw(data->menu->win, "%d", data->ligne);
    wmove(data->menu->win, 8, 8);
    wprintw(data->menu->win, "%d", data->level);
    wmove(data->menu->win, 11, 8);
    wprintw(data->menu->win, "%d", data->score);
    wmove(data->menu->win, 13, 7);
    wprintw(data->menu->win, "%ld", data->time);
}

void game9(data_t *data, global_data_t *gdata)
{
    if (data->width_win+1 < COLS && data->height_win+1 < LINES) {
        disp_map(data);
        game5(data, gdata);
        game6(data, gdata);
        game7(data);
        game8(data);
        wnoutrefresh(data->win);
        wnoutrefresh(data->menu->win);
        wnoutrefresh(data->game->win);
        wnoutrefresh(data->next->win);
        doupdate();
    }
    data->c = getch();
    if (data->c == gdata->key_quit) {
        endwin();
        exit(0);
    }
}

void game10(data_t *data, global_data_t *gdata)
{
    if ((data->c == 410 || data->c == 0) && (data->width_\
win+1 >= COLS || data->height_win+1 >= LINES)) {
        clear();
        wclear(data->win);
        mvprintw(LINES/2, (COLS / 2) - (7), "invalide size");
    }
    game4(data);
    game9(data, gdata);
    if (data->c == gdata->key_pause && data->tmp == 1 && data->touche == 0) {
        data->tmp = 0;
        nodelay(stdscr, true);
        data->touche = 1;
    }
}

void game11(data_t *data, global_data_t *gdata)
{
    while (1) {
        game10(data, gdata);
        if (data->c == gdata->key_pause && data->tmp \
== 0 && data->touche == 0) {
            data->tmp = 1;
            nodelay(stdscr, false);
            data->touche = 1;
        }
        data->touche = 0;
    }
}

void game(global_data_t *gdata)
{
    data_t *data = init_data(gdata);

    game2(gdata, data);
    game3();
    data->next_tetri = chose_tetriminos(data);
    data->win = newwin(data->height_win, data->width_win, 0, 0);
    data->menu->win = newwin(data->menu->height, \
data->menu->width, 1, 1);
    data->game->win = newwin(data->game->height, \
data->game->width, 1, data->menu->width +1);
    data->next->win = newwin(data->next->height, \
data->next->width, 1, data->menu->width + data->game->width +2);
    game11(data, gdata);
    endwin();
}