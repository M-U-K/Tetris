/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_data2
*/

#include "tetris.h"

int verif_tetriminos_file(char const *str)
{
    int tmp = 0;
    int y = 0;
    int i = 0;
    char *tetri = "tetriminos";

    if (str[0] == '.')
        return (84);
    for (; str[i] != '\0'; i++) {
        if (tmp == 1 && str[i] != tetri[y])
            return (84);
        if (tmp == 1)
            y++;
        if (str[i] == '.')
            tmp = 1;
    }
    if (tmp == 0)
        return (84);
    return (0);
}

char *my_concat(char *str1, const char *str2)
{
    int cmp = 0;
    char *result = malloc(str_len(str1) + str_len(str2) + 1);
    for (int i = 0; str1[i] != '\0'; i++, cmp++)
        result[cmp] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++, cmp++)
        result[cmp] = str2[i];
    result[cmp] = '\0';
    return (result);
}

int recup_nbr_str(int i, char *str)
{
    int len = 0;
    int cmp = 0;
    char *height;

    for (int y = i; (str[y] < 58 || str[y] > 47) && str[y] \
!= '\0' && str[y] != '\n' && str[y] != ' '; y++)
        len++;
    height = malloc(sizeof(char) * (len+1));
    for (int y = i; (str[y] < 58 || str[y] > 47) && str[y] \
!= '\0' && str[y] != '\n' && str[y] != ' '; y++, cmp++)
        height[cmp] = str[y];
    height[cmp] = '\0';
    return (get_number(height));
}

int check_tetriminos3(int nbr_first_line, int height, int i, char *str)
{
    if (nbr_first_line == 2)
        height = recup_nbr_str(i, str);
    return (height);
}

int check_tetriminos2(char *str, int i, data_t *data)
{
    for (; (str[i] < 58 || str[i] > 47) && str[i] \
!= '\0' && str[i] != '\n' && str[i] != ' '; i++)
        if (str[i] != ' ' && (str[i] <= 47 || str[i] >= 58))
            data->exit = 1;
    return (i);
}
