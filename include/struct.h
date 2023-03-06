/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** struct
*/

#include "tetris.h"


#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct {
    int color;
    int height;
    int width;
    char *tetri_str;
    char **tetri;
} tetriminos_t;

typedef struct {
    int width;
    int height;
    int x_full_line;
    int y_full_line;
    int x_level;
    int y_leve;
    int x_hight_score;
    int y_hight_score;
    int x_score;
    int y_score;
    WINDOW *win;
} menu_t;

typedef struct {
    int width;
    int height;
    WINDOW *win;
} game_t;

typedef struct {
    WINDOW *win;
    int width;
    int height;
} next_t;

typedef struct {
    int color;
    int height;
    int width;
    char **tetri;
} tetri_t;

typedef struct {
    int x2;
    int y2;
    int x;
    int y;
    int c;
    int tmp;
    int touche;
    int nbr_first_line;
    int exit;
    long time;
    long time_mili;
    int ligne;
    int level;
    int score;
    clock_t start_mili;
    clock_t start;
    clock_t actual;
    int can_start;
    int width_max_tetri;
    int height_max_tetri;
    int nbr_tetriminos;
    int width_win;
    int height_win;
    char **map;
    int next_tetri;
    int actual_tetri;
    int can_move;
    int pos_tetri_x;
    int pos_tetri_y;
    int boost_lvl;
    WINDOW *win;
    tetri_t *next_tetri2;
    tetri_t *tetri;
    menu_t *menu;
    game_t *game;
    next_t *next;
    tetriminos_t **tetriminos;
} data_t;

#endif
