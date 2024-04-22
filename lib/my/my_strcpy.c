/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Task01
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    if (!dest || !src)
    return NULL;
    while (src[a] != '\0') {
        dest[a] = src[a];
        a += 1;
    }
    dest[a] = '\0';
    return dest;
}
