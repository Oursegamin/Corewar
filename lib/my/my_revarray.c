/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_revarray
*/

#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"
#include <stdio.h>

void my_revarray(char **array)
{
    int len = my_arraylen(array) - 1;
    int nb = len;

    for (; nb >= 0; nb -= 1) {
        my_putstr(array[nb]);
        if (nb != 0)
            my_putstr("  ");
    }
}
