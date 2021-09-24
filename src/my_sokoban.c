/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void sokoko(v_var *a, int i)
{
    display_map(a);
    i = getch();
    if (i == -1)
        exit(84);
    else
        check_key(a, i);
}

int my_sokoban(v_var *a)
{
    int i = 0;

    initscr();
    keypad(stdscr, TRUE);
    refresh();
    curs_set(FALSE);
    while (1) {
        clear();
        sokoko(a, i);
        if (a->win == 1) {
            endwin();
            return (1);
        } else if (a->win == 2) {
            endwin();
            return (0);
        }
        refresh();
    }
    endwin();
    return (0);
}

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr(" containing '#' for walls,\n          'P' for the player");
    my_putstr(", 'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    v_var *a = malloc(sizeof(v_var));

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            usage();
            return (0);
        }
        my_maps(a, av[1]);
        find_player(a);
        if (my_sokoban(a) == 1)
            return (1);
    } else
        return (84);
    return (0);
}