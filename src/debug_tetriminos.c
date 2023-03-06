/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug_tetriminos.c
*/

#include "tetris.h"

char **take_files_list(void)
{
    char **files_list = NULL;
    struct dirent *st_dir = malloc(sizeof(struct dirent));
    DIR *dir = opendir("tetriminos");

    while (dir != NULL) {
        st_dir = readdir(dir);
        if (st_dir == NULL)
            break;
        if (st_dir->d_name[0] != '.'
        && search_n_occurence(st_dir->d_name, ".tetrimino", -1)
        == (string_len(st_dir->d_name, '\0') - 10))
            files_list = tab_append(files_list, st_dir->d_name);
    }
    closedir(dir);
    return (files_list);
}

bool check_valid_tetrimino(char **content, char *name, int line)
{
    for (int col = 0; content[line][col] != '\0'; col += 1)
        if (is_in_string(content[line][col], "* ") == false) {
            my_printf("Tetriminos :  Name %s :  Error\n", name);
            return (false);
        }
    return (true);
}

void print_tetrimino(char *name, char **content)
{
    int value[3] = {-1, -1, -1};

    if (is_num(content[0], " ") == false) {
        my_printf("Tetriminos :  Name %s :  Error\n", name);
        return;
    }
    value[0] = content[0][0];
    value[1] = content[0][2];
    value[2] = content[0][4];
    for (int line = 1; content[line] != NULL; line += 1)
        if (check_valid_tetrimino(content, name, line) == false)
            return;
    my_printf("Tetriminos :  Name %s :  Size %c*%c :  Color %c :\n",
    name, value[0], value[1], value[2]);
    for (int ctr = 1; content[ctr] != NULL; ctr += 1)
        my_printf("%s\n", content[ctr]);
}

void debug_tetriminos(void)
{
    char *tmp_string_content = NULL;
    char **tmp_content = NULL;
    char **files_list = take_files_list();
    int check = 0;

    files_list = sort_word(files_list);
    my_printf("Tetriminos :  %i\n", table_len(files_list));
    if (files_list == NULL)
        return;
    for (int ctr = 0; files_list[ctr] != NULL; ctr += 1) {
        tmp_string_content =\
        read_stat_file(concat_fstring("tetriminos/%s", files_list[ctr]));
        if (tmp_string_content == NULL)
            continue;
        tmp_content = str_to_tab(tmp_string_content, "\n");
        check = search_n_occurence(files_list[ctr], ".tetrimino", -1);
        files_list[ctr] = my_realloc(files_list[ctr], check, true, false);
        print_tetrimino(files_list[ctr], tmp_content);
    }
}