/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** task01
*/

#include "my.h"

void my_swap(void *a, void *b, int size_a, int size_b)
{
    uint8_t *tmp = NULL;
    uint8_t *uint_a = (uint8_t *)a;
    uint8_t *uint_b = (uint8_t *)b;

    tmp = malloc(sizeof(uint8_t) * size_a);
    my_memcpy(tmp, uint_a, size_a);
    my_memcpy(uint_a, uint_b, size_b);
    my_memcpy(uint_b, tmp, size_a);
    free(tmp);
}
