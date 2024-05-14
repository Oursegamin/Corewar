/*
** EPITECH PROJECT, 2023
** day08
** File description:
** task01
*/

#include "my.h"

uint8_t *my_uint8_ndup(uint8_t const *src, int n)
{
    uint8_t *str;
    int i = 0;

    if (!src)
        return NULL;
    str = malloc(sizeof(uint8_t) * (n + 1));
    for (; i < n && src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
