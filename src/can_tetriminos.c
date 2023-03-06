/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_data4
*/

#include "tetris.h"

int can_tetriminos(char const *str, data_t *data)
{
    int check = 0;
    char *tmp = my_concat("tetriminos/", str);
    char *read = read_stat_file(tmp);

    check = check_tetriminos(read, data);
    if (check == 0)
        return (1);
    if (check == 1)
        return (0);
    return (0);
}

int add_tetriminos2(tetriminos_t *tetri, int nbr_first_line, int i, char *str)
{
    if (nbr_first_line == 1)
        tetri->width = recup_nbr_str(i, str);
    if (nbr_first_line == 2)
        tetri->height = recup_nbr_str(i, str);
    if (nbr_first_line == 3)
        tetri->color = recup_nbr_str(i, str);
    for (; (str[i] < 58 || str[i] > 47) && str[i] \
!= '\0' && str[i] != '\n' && str[i] != ' '; i++);
    return (i);
}

int add_tetriminos3(char *str, int i, tetriminos_t *tetri, int y)
{
    int x = 0;
    for (x = 0; str[i] != '\0' && str[i] != '\n'; i++, x++)
        if (x <= tetri->width)
            tetri->tetri[y][x] = str[i];
    if (x <= tetri->width)
        tetri->tetri[y][x] = '\0';
    else
        tetri->tetri[y][tetri->width] = '\0';
    i++;
    return (i);
}

void add_tetriminos(char const *str1, tetriminos_t *tetri)
{
    char *tmp = my_concat("tetriminos/", str1);
    char *str = read_stat_file(tmp);
    int i = 0;
    int nbr_first_line = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++)
        if (str[i] < 58 && str[i] > 47) {
            nbr_first_line++;
            i = add_tetriminos2(tetri, nbr_first_line, i, str);
            i--;
        }
    tetri->tetri = malloc(sizeof(char *) * (tetri->height+1));
    for (int y = 0; y != tetri->height; y ++)
        tetri->tetri[y] = malloc(sizeof(char) * (tetri->width+1));
    tetri->tetri[tetri->height] = NULL;
    i++;
    for (int y = 0; y != tetri->height; y++) {
        i = add_tetriminos3(str, i , tetri, y);
    }
    return;
}

int init_data2(data_t *data, struct dirent *dent, int cmp)
{
    if (verif_tetriminos_file(dent->d_name) == 0)
        if (can_tetriminos(dent->d_name, data) == 0) {
            add_tetriminos(dent->d_name, data->tetriminos[cmp]);
            cmp++;
        }
    return (cmp);
}
