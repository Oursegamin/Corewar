/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** my_corcpy
*/

#include "my.h"

void my_corcpy(uint8_t arena[][MEM_SIZE], int pc, uint8_t *value, int size)
{
    for (int i = 0; i < size; i++)
        (*arena)[(pc + i) % MEM_SIZE] = value[i];
}
