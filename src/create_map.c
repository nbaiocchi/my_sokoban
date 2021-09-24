/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../include/prototype.h"

void create_map2(v_var *a, char *buff, int i)
{
    int y = 0;
    int z = 0;

    a->map[i] = NULL;
    for (int r = 0; buff[r] != '\0'; r += 1) {
        if (buff[r] == '\n' || buff[r] == '\0') {
            a->map[y][z] = '\0';
            r += 1;
            y += 1;
            z = 0;
        }
        a->map[y][z] = buff[r];
        z += 1;
    }
    a->size = i;
}

void creat_map(v_var *a, char *buff)
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
    a->map = malloc(sizeof(char *) * (y + 1));
    while (z != (y + 1)) {
        a->map[z] = malloc(sizeof(char) * 250);
        z += 1;
    }
    create_map2(a, buff, y);
}

char *check_error(char *buff)
{
    int i = 0;

    while (buff[i] != '\0') {
        i += 1;
    }
    if (buff[i - 1] == '\n') {
        buff[i - 1] = '\0';
    }
    return (buff);
}

int my_maps(v_var *a, char *path)
{
    struct stat buf;
    int fd;
    int ret = 0;
    char *buff;
    stat(path, &buf);
    buff = malloc(sizeof(char) * buf.st_size + 1);
    fd = open(path, O_RDONLY);
    if (fd == -1)
    	return (84);
    ret = read(fd, buff, buf.st_size);
    if (ret <= 0)
    	return (84);
    buff[ret] = '\0';
    fd = close(fd);
    buff = check_error(buff);
    creat_map(a, buff);
    copy_map(a, buff);
    check_buff(a, buff);
    return (0);
}

void display_map(v_var *a)
{
    for (int row = 0; row < a->size; row += 1)
        mvprintw(row, 0, "%s", a->map[row]);
}