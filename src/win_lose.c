/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

int check(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 'O')
            return (1);
    }
    return (0);
}

int check_win(v_var *a)
{
    int i = 0;

    while (i != a->size) {
        if (check(a->map[i]) == 1)
            return (1);
        i += 1;
    }
    refresh();
    clear();
    display_map(a);
    return (0);
}

int check_angle(v_var *a, int i, int r)
{
    if (a->map[i][r] == 'X' &&
    a->map[i - 1][r] == '#' && a->map[i][r + 1] == '#')
        return (1);
    if (a->map[i][r] == 'X' &&
    a->map[i][r + 1] == '#' && a->map[i + 1][r] == '#')
        return (1);
    if (a->map[i][r] == 'X' &&
    a->map[i + 1][r] == '#' && a->map[i][r - 1] == '#')
        return (1);
    if (a->map[i][r] == 'X' &&
    a->map[i][r - 1] == '#' && a->map[i - 1][r] == '#')
        return (1);
    return (0);
}

int check_x(v_var *a, int i)
{
    int r = 0;

    while (a->map[i][r] != '\0') {
        if (check_angle(a, i, r) == 1) {
            a->calc += 1;
        }
        r += 1;
    }
    return (0);
}

int check_lose(v_var *a)
{
    int i = 1;
    a->calc = 0;

    while (i != (a->size - 1)) {
        check_x(a, i);
        i += 1;
    }
    if (a->calc == a->X)
        return (0);
    refresh();
    clear();
    display_map(a);
    return (1);
}