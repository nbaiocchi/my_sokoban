/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void copy_map2(v_var *a, char *buff, int i)
{
    int y = 0;
    int z = 0;

    a->copy_map[i] = NULL;
    for (int r = 0; buff[r] != '\0'; r += 1) {
        if (buff[r] == '\n' || buff[r] == '\0') {
            a->copy_map[y][z] = '\0';
            r += 1;
            y += 1;
            z = 0;
        }
        a->copy_map[y][z] = buff[r];
        z += 1;
    }
    a->size = i;
}

void copy_map(v_var *a, char *buff)
{
    int i = 0;
    int z = 0;
    int y = 0;

    while (buff[i] != '\n') {
        i += 1;
    }
    while (buff[z] != '\0') {
        if (buff[z] == '\n')
            y += 1;
        z += 1;
    }
    y += 1;
    z = 0;
    a->copy_map = malloc(sizeof(char *) * (y + 1));
    while (z != (y + 1)) {
        a->copy_map[z] = malloc(sizeof(char) * 200);
        z += 1;
    }
    copy_map2(a, buff, y);
}