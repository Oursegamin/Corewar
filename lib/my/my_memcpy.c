/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** my_memcpy
*/

#include "my.h"

void my_memcpy(void *dest, const void *src, size_t n)
{
    uint8_t *csrc = (uint8_t *)src;
    uint8_t *cdest = (uint8_t *)dest;

    for (size_t i = 0; i < n; i++)
        cdest[i] = csrc[i];
}
