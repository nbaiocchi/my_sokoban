/*
** EPITECH PROJECT, 2020
** prototype.h
** File description:
** t
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ncurses.h>

typedef struct v_variable
{
    char **map;
    char **copy_map;
    int size;
    int large;
    int longe;
    int copy_large;
    int copy_longe;
    int O;
    int P;
    int X;
    int win;
    int bloc;
    int calc;
} v_var;

int my_maps(v_var *a, char *path);
void display_map(v_var *a);
void check_key(v_var *a, int i);
void find_player(v_var *a);
void copy_map(v_var *a, char *buff);
void check_buff(v_var *a, char *buff);

void reset_map(v_var *a);
int check_win(v_var *a);
void check_o(v_var *a);
void coding_style3(v_var *a, int *i, int *y, int *t);
void coding_style(v_var *a, int *i, int *y, int *t);
int check_lose(v_var *a);

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strdup(char *str);

#endif /* !PROTOTYPE_H_ */
