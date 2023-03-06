/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.c
*/

#include "tetris.h"

void my_getch(void)
{
    struct termios old;
    struct termios new;
    char buf[20];

    ioctl(0, TCGETS, &old);
    ioctl(0, TCGETS, &new);
    new.c_lflag &= ~ECHO;
    new.c_lflag &= ~ICANON;
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;
    ioctl(0, TCSETS, &new);
    read(0, buf, 20);
    ioctl(0, TCSETS, &old);
}

void disp_value(char *str, int value)
{
    switch (value) {
    case ' ':
        my_printf("%s  (space)\n", str);
        break;
    case 65:
        my_printf("%s  ^EOA\n", str);
        break;
    case 66:
        my_printf("%s  ^EOB\n", str);
        break;
    case 67:
        my_printf("%s  ^EOC\n", str);
        break;
    case 68:
        my_printf("%s  ^EOD\n", str);
        break;
    default:
        my_printf("%s  %c\n", str, value);
    }
}

void debug(global_data_t *gdata)
{
    my_printf("*** DEBUG MODE ***\n");
    disp_value("Key Left :", gdata->key_left);
    disp_value("Key Right :", gdata->key_right);
    disp_value("Key Turn :", gdata->key_turn);
    disp_value("Key Drop :", gdata->key_drop);
    disp_value("Key Quit :", gdata->key_quit);
    disp_value("Key Pause :", gdata->key_pause);
    my_printf("Next :  ");
    gdata->without_next == false ? my_printf("Yes\n") : my_printf("No\n");
    my_printf("Level :  %i\n", gdata->level);
    my_printf("Size :  %i*%i\n", gdata->height, gdata->width);
    debug_tetriminos();
    my_printf("Press any key to start Tetris\n");
    my_getch();
}