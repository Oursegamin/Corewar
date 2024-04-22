/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_errchar
*/

#include <unistd.h>

void my_put_errchar(char c)
{
    write(2, &c, 1);
}
