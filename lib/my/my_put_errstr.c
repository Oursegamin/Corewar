/*
** EPITECH PROJECT, 2023
** day04
** File description:
** task02
*/

#include "my.h"

int my_put_errstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_put_errchar(str[i]);
        i += 1;
    }
    return (i);
}
