/*
** EPITECH PROJECT, 2023
** day08
** File description:
** task01
*/

#include "my.h"

uint8_t *my_uint8_ndup(uint8_t *arena, int pc, int size)
{
    uint8_t *str;

    if (!arena)
        return NULL;
    str = malloc(sizeof(uint8_t) * size);
    for (int i = 0; i < size; i++)
        str[i] = arena[(pc + i) % MEM_SIZE];
    return str;
}
