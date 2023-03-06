/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_data3
*/

#include "tetris.h"

void check_tetriminos4(data_t *data, int i, char *str)
{
    if (str[i] != ' ' && str[i] != '*' && str[i] != '\n')
        data->exit = 1;
}

int check_tetriminos5(int i, char *str, data_t *data, int height)
{
    if (data->nbr_first_line != 3)
        return (0);
    i++;
    for (int h = 0; h != height; h++) {
        for (; str[i] != '\0' && str[i] != '\n'; i++) {
            check_tetriminos4(data, i, str);
        }
        if (data->exit == 1) {
            data->exit = 0;
            return (0);
        }
        i++;
    }
    return (1);
}

int check_tetriminos6(char *str, int height, int i, data_t *data)
{
    if (str[i] < 58 && str[i] > 47) {
        data->nbr_first_line++;
        height = check_tetriminos3(data->nbr_first_line, height, i, str);
        i = check_tetriminos2(str, i, data);
        i--;
    }
    return (i);
}

int check_tetriminos(char *str, data_t *data)
{
    int i = 0;
    int height = 0;
    data->nbr_first_line = 0;
    data->exit = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] != ' ' && (str[i] <= 47 || str[i] >= 58))
            return (0);
        i = check_tetriminos6(str, height, i , data);
        if (data->exit == 1) {
            data->exit = 0;
            return (0);
        }
    }
    if (check_tetriminos5(i, str, data, height) == 0)
        return (0);
    return (1);
}

void find_nbr_tetriminos(char const *str, data_t *data)
{
    int check = 0;
    char *tmp = my_concat("tetriminos/", str);
    char *read = read_stat_file(tmp);

    check = check_tetriminos(read, data);
    if (check == 0)
        return;
    if (check == 1) {
        data->nbr_tetriminos++;
        return;
    }
}