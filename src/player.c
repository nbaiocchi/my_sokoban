/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void cc_style(v_var *a, int i, int b)
{
    if (a->copy_map[i][b] == 'P') {
        a->longe = i;
        a->large = b;
    }
}

void find_player(v_var *a)
{
    int i = 0;
    int b = 0;

    while (i != a->size) {
        while (a->copy_map[i][b] != '\0') {
            cc_style(a, i, b);
            b += 1;
        }
        b = 0;
        i += 1;
    }
    if (a->large == 0)
        exit(84);
    a->copy_large = a->large;
    a->copy_longe = a->longe;
}