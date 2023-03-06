/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_data
*/

#include "tetris.h"


void init_data3(struct dirent *dent, data_t *data)
{
    if (verif_tetriminos_file(dent->d_name) == 0)
        find_nbr_tetriminos(dent->d_name, data);
}

void init_data4(data_t *data, global_data_t \
*gdata, int cmp, struct dirent *dent)
{
    DIR *dir;
    char *buffer = "tetriminos/";

    for (int i = 0; i != data->nbr_tetriminos; i++)
        data->tetriminos[i] = malloc(sizeof(tetriminos_t));
    data->tetriminos[data->nbr_tetriminos+1] = NULL;
    dir = opendir(buffer);
    if (dir!=NULL)
        while ((dent=readdir(dir))!=NULL)
            cmp = init_data2(data, dent, cmp);
    data->can_move = 0;
    closedir(dir);
    data->start_mili = clock();
    data->start = clock();
    data->level = gdata->level;
    data->ligne = 0;
    data->next_tetri = 0;
    data->score = 0;
}

data_t *init_data(global_data_t *gdata)
{
    data_t *data = malloc(sizeof(data_t));
    int cmp = 0;
    data->nbr_tetriminos = 0;
    data->can_start = 0;
    DIR *dir;
    struct dirent *dent;
    char *buffer = "tetriminos/";
    dir = opendir(buffer);
    if (dir!=NULL) {
        data->can_start = 1;
        while ((dent=readdir(dir))!=NULL)
            init_data3(dent, data);
    }
    closedir(dir);
    data->tetriminos = malloc(sizeof(tetriminos_t) * (data->nbr_tetriminos+1));
    init_data4(data, gdata, cmp, dent);
    return (data);
}