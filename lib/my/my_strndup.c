/*
** EPITECH PROJECT, 2023
** day08
** File description:
** task01
*/

#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *str;

    if (!src)
        return NULL;
    str = malloc(n + 1);
    my_strncpy(str, src, n);
    return (str);
}
