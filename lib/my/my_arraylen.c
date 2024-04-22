/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_arraylen
*/

#include "my.h"

int my_arraylen(char **array)
{
    int a = 0;

    while (array[a] != NULL) {
        a += 1;
    }
    return (a);
}
