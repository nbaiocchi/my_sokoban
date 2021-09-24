/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void check_map(v_var *a, char *buff)
{
    int y = 0;
    int lenth = 0;

    if (a->O != a->X) {
        my_putstr("error");
        exit(84);
    }
    while (buff[y] != '\0') {
        y += 1;
    }
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == '#' || buff[i] == 'X' || buff[i] == ' ' ||
        buff[i] == 'O' || buff[i] == '\n' || buff[i] == 'P')
            lenth += 1;
    }
    if (lenth != y) {
        my_putstr("error");
        exit(84);
    }
}

void check_buff(v_var *a, char *buff)
{
    a->O = 0;

    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == 'O')
            a->O += 1;
    }
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == 'X')
            a->X += 1;
    }
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == 'P')
            a->P += 1;
    }
    if (a->O == 0 || a->X == 0 || a->P == 0) {
        my_putstr("error");
        exit(84);
    }
    check_map(a, buff);
}