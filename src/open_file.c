/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** open-file
*/

#include "my.h"

int fs_open_file(const char *file)
{
    int fd = 0;
    char *buffer = NULL;
    int size = 0;
    struct stat s;

    stat(file, &s);
    size = s.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    fd = open(file, O_RDONLY);
    if (fd == ERR)
        return (KO);
    size = read(fd, buffer, size);
    buffer[size] = '\0';
    my_putstr(buffer);
    return OK;
}
