/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** fct
*/

#include "tetris.h"

#ifndef FCT_H_
#define FCT_H_

//init_data.c
int verif_tetriminos_file(char const *str);
char *my_concat(char *str1, const char *str2);
int recup_nbr_str(int i, char *str);
int check_tetriminos3(int nbr_first_line, int height, int i, char *str);
int check_tetriminos2(char *str, int i, data_t *data);
data_t *init_data(global_data_t *gdata);
void find_nbr_tetriminos(char const *str, data_t *data);
int check_tetriminos(char *str, data_t *data);
int init_data2(data_t *data, struct dirent *dent, int cmp);
void change_setting_data(data_t *data, global_data_t *gdata);
void disp5(data_t *data);
void disp_map(data_t *data);
void disp_tetriminos(data_t *data);
int chose_tetriminos(data_t *data);
void disp3(data_t *data);
void disp_tetriminos_end(data_t *data);
void turn5(data_t *data, char **tetri, int height, int width);
int turn4(data_t *data);
char **turn3(data_t *data, char **tetri);
void turn2(data_t *data);
char ** turn_tetri(data_t *data);
void move10(data_t *data);
void move6(data_t *data);
int move11(data_t *data);
int move12(data_t *data);
void move13(data_t *data);
void move_right(data_t *data);
void move5(data_t *data);
int move7(data_t *data);
void move9(data_t *data);
int move8(data_t *data);
void move_left(data_t *data);
void remove_space(data_t *data);
void move2(data_t *data);
int move3(data_t *data);
int move4(data_t *data);
void move_down(data_t *data);
void set_tetri(data_t *data);
void set_next_tetri(data_t *data);
int all_line(char *str);
void find_line3(data_t *data);
void find_line2(data_t *data);
void find_line(data_t *data);
void game2(global_data_t *gdata, data_t *data);
void game3(void);
void game4(data_t *data);
void game5(data_t *data, global_data_t *gdata);
void game6(data_t *data, global_data_t *gdata);
void game71(data_t *data);
void game7(data_t *data);

#endif
