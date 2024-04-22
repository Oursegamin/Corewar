/*
** EPITECH PROJECT, 2023
** day06
** File description:
** task02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    while (i < n) {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
