/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** load_in_arena
*/

#include "my.h"
static int calculate_padding(corewar_t *corewar)
{
    int i = 0;
    int n = 0;
    int padding = 0;

    if (!corewar)
        return -KO;
    for (; corewar->champions[i] != NULL; i += 1) {
        n += corewar->champions[i]->prog_size;
    }
    padding = (n - MEM_SIZE) / (i + 1);
    return padding;
}

int load_in_arena(corewar_t *corewar)
{
    int padding = calculate_padding(corewar);

    if (padding == -KO)
        return KO;
    for (int i = 0; corewar->champions[i] != NULL; i += 1) {
        corewar->
    }
    return (0);
}
