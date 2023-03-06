/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris.h
*/

#ifndef TETRIS_H
#define TETRIS_H

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>

#include "utils.h"
#include "printf.h"
#include "struct.h"

typedef unsigned int uint;

typedef struct {
    uint level;
    uint height;
    uint width;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    bool without_next;
    bool debug;
    char *binary_name;
} global_data_t;
#include "fct.h"

global_data_t *init(void);

void debug(global_data_t *gdata);
void debug_tetriminos(void);

void case_h(char *binary_name);
int take_param_first(global_data_t *gdata, int index, char *value);
int take_param_second(global_data_t *gdata, int index, char *value);
int take_param_third(global_data_t *gdata, int index, char *value);
int take_param_fourth(global_data_t *gdata, int index, char *value);
int take_param_fifth(global_data_t *gdata, int index, char *value);
int check_parameters(global_data_t *gdata, int ac, char **av);
bool check_key(char *value);
bool take_map_size(global_data_t *gdata, char *value);

void game(global_data_t *gdata);

#endif