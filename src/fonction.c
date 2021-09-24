/*
** EPITECH PROJECT, 2020
** fonction.c
** File description:
** t
*/

#include "../include/prototype.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x = x + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 0) {
        if (nb > 9)
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (0);
}

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        x++;
    }
    return (x);
}

char *my_strdup(char *str)
{
    char *result;
    int i = 0;

    result = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i]) {
        result[i] = str[i];
        i++;
    }
    result[i] = 0;
    return (result);
}