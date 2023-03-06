/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** game2
*/

#include "tetris.h"

void disp_map(data_t *data)
{
    wmove(data->menu->win, 0, 0);
    wprintw(data->menu->win, "/-------------------------------\
-------------------------\\\n");
    wprintw(data->menu->win, "|          * * *  * * *  * * *  \
* * *  *  * * *          |\n");
    wprintw(data->menu->win, "|            *    *        *    \
*   *     *              |\n");
    wprintw(data->menu->win, "|            *    * *      *    \
* *    *  * * *          |\n");
    wprintw(data->menu->win, "|            *    *        *    \
*   *  *      *          |\n");
    wprintw(data->menu->win, "|            *    * * *    *    \
*   *  *  * * *          |\n");
    wprintw(data->menu->win, "\\------------------------------\
--------------------------/\n");
    disp5(data);
}

int chose_tetriminos(data_t *data)
{
    int tetri = rand()%data->nbr_tetriminos;
    return (tetri);
}

void disp4(data_t *data)
{
    if (data->tetri->tetri[data->y2][data->x2] != ' ')
        data->map[data->y][data->x] = data->tetri->tetri\
[data->y2][data->x2];
}

void disp_tetriminos(data_t *data)
{
    for (data->y = data->pos_tetri_y, data->y2 = 0; data->y != \
data->tetri->height+data->pos_tetri_y; data->y ++, data->y2 ++) {
        for (data->x = data->pos_tetri_x, data->x2 = 0; data->\
tetri->tetri[data->y2][data->x2] != '\0'; data->x++, data->x2++) {
            disp4(data);
        }
    }
}

void disp3(data_t *data)
{
    if (data->map[data->y][data->x] == '*') {
        endwin();
        printf("Perdu\n");
        exit(0);
    }
    if (data->tetri->tetri[data->y2][data->x2] != ' ')
        data->map[data->y][data->x] = data->tetri->tetri[data->y2][data->x2];
}