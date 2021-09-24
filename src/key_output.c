/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void key_up(v_var *a)
{
    if (a->map[a->longe - 1][a->large] == ' ' ||
    a->map[a->longe - 1][a->large] == 'O') {
        a->map[a->longe][a->large] = ' ';
        a->longe -= 1;
        a->map[a->longe][a->large] = 'P';
    }
    if (a->map[a->longe - 1][a->large] == 'X'
    && a->map[a->longe - 2][a->large] != '#' &&
    a->map[a->longe - 2][a->large] != 'X') {
        a->map[a->longe][a->large] = ' ';
        a->longe -= 1;
        a->map[a->longe][a->large] = 'P';
        a->map[a->longe - 1][a->large] = 'X';
    }
}

void key_down(v_var *a)
{
    if (a->map[a->longe + 1][a->large] == ' ' ||
    a->map[a->longe + 1][a->large] == 'O') {
        a->map[a->longe][a->large] = ' ';
        a->longe += 1;
        a->map[a->longe][a->large] = 'P';
    }
    if (a->map[a->longe + 1][a->large] == 'X'
    && a->map[a->longe + 2][a->large] != '#' &&
    a->map[a->longe + 2][a->large] != 'X') {
        a->map[a->longe][a->large] = ' ';
        a->longe += 1;
        a->map[a->longe][a->large] = 'P';
        a->map[a->longe + 1][a->large] = 'X';
    }
}

void key_left(v_var *a)
{
    if (a->map[a->longe][a->large - 1] == ' ' ||
    a->map[a->longe][a->large - 1] == 'O') {
        a->map[a->longe][a->large] = ' ';
        a->large -= 1;
        a->map[a->longe][a->large] = 'P';
    }
    if (a->map[a->longe][a->large - 1] == 'X'
    && a->map[a->longe][a->large - 2] != '#' &&
    a->map[a->longe][a->large - 2] != 'X') {
        a->map[a->longe][a->large] = ' ';
        a->large -= 1;
        a->map[a->longe][a->large] = 'P';
        a->map[a->longe][a->large - 1] = 'X';
    }
}

void key_right(v_var *a)
{
    if (a->map[a->longe][a->large + 1] == ' ' ||
    a->map[a->longe][a->large + 1] == 'O') {
        a->map[a->longe][a->large] = ' ';
        a->large += 1;
        a->map[a->longe][a->large] = 'P';
    }
    if (a->map[a->longe][a->large + 1] == 'X'
    && a->map[a->longe][a->large + 2] != '#' &&
    a->map[a->longe][a->large + 2] != 'X') {
        a->map[a->longe][a->large] = ' ';
        a->large += 1;
        a->map[a->longe][a->large] = 'P';
        a->map[a->longe][a->large + 1] = 'X';
    }
}

void check_key(v_var *a, int i)
{
    a->win = 0;
    if (i == KEY_UP)
        key_up(a);
    if (i == KEY_DOWN)
        key_down(a);
    if (i == KEY_LEFT)
        key_left(a);
    if (i == KEY_RIGHT)
        key_right(a);
    if (i == ' ')
        reset_map(a);
    check_o(a);
    if (check_win(a) == 0)
        a->win = 1;
    if (check_lose(a) == 0)
        a->win = 2;
}