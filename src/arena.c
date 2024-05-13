/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** arena
*/

#include "my.h"

static int (*intructions[16])(corewar_t *, champion_t **, int) = {
    live,
    ld_i,
    st_i,
    add,
    sub,
    and_i,
    or_i,
    xor_i,
    zjmp,
    ldi,
    sti,
    fork_i,
    lld,
    lldi,
    lfork,
    aff
};

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

static void execute_champion(corewar_t *corewar)
{
    for (int i = 0; corewar->champions[i] != NULL; i++) {
        if (!corewar->champions[i]->is_alive)
            continue;
        if (corewar->arena[corewar->champions[i]->PC] < 17 &&
            corewar->arena[corewar->champions[i]->PC] > 0 &&
            intructions[corewar->arena[corewar->champions[i]->PC]]
            (corewar, corewar->champions, i) == KO) {
            corewar->champions[i]->is_alive = false;
        } else
            corewar->champions[i]->is_alive = false;
    }
}

int champion_arena(corewar_t *corewar)
{
    while (1) {
        if (is_alive(corewar->champions) == KO)
            break;
        execute_champion(corewar);
    }
    return OK;
}
