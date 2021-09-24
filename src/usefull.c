/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void reset_map(v_var *a)
{
    int i = 0;
    int f = 0;

    a->map = NULL;
    while (a->copy_map[i] != NULL)
        i += 1;
    a->map = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j != i; j += 1) {
        a->map[j] = my_strdup(a->copy_map[j]);
        f = j;
    }
    a->map[f+1] = NULL;
    a->large = a->copy_large;
    a->longe = a->copy_longe;
}

void check_o(v_var *a)
{
    int i = 0;
    int b = 0;

    while (i != a->size) {
        while (a->copy_map[i][b] != '\0') {
            if (a->copy_map[i][b] == 'O' && a->map[i][b] == ' ') {
                a->map[i][b] = 'O';
            }
            b += 1;
        }
        b = 0;
        i += 1;
    }
}