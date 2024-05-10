/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** arena
*/

#include "my.h"

static int is_alive(champion_t **champion)
{
    int end = 0;

    for (int i = 0; champion[i] != NULL; i++) {
        if (champion[i]->is_alive == true)
            end += 1;
    }
    if (end == 1)
        return KO;
    return OK;
}

int champion_arena(corewar_t *corewar)
{
    while (1) {
        if (is_alive(corewar->champions) == KO)
            break;
        for (int i = 0; corewar->champions[i] != NULL; i++) {
            
        }
    }
}
