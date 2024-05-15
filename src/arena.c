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

static int cycle_delta(corewar_t *corewar)
{
    int cycle_to_remove = CYCLE_DELTA * corewar->current_nbr_live / 40;

    if (cycle_to_remove <= 0)
        return 1;
    return cycle_to_remove;
}

static void execute_champion(corewar_t *corewar)
{
    for (int i = 0; corewar->champions[i] != NULL; i++) {
        if (is_alive(corewar->champions) == KO)
            break;
        if (corewar->champions[i]->cycle_to_die <= 0)
            corewar->champions[i]->is_alive = false;
        if (!corewar->champions[i]->is_alive)
            continue;
        if (corewar->champions[i]->cycle_to_wait > 0) {
            corewar->champions[i]->cycle_to_wait -= 1;
            continue;
        }
        // printf("%d", corewar->champions[i]->PC);
        if (corewar->arena[corewar->champions[i]->PC] > 16 ||
            corewar->arena[corewar->champions[i]->PC] < 1 ||
            intructions[corewar->arena[corewar->champions[i]->PC] - 1]
            (corewar, corewar->champions, i) == KO) {
            corewar->champions[i]->is_alive = false;
        }
        corewar->champions[i]->cycle_to_die -= cycle_delta(corewar);
    }
}

int champion_arena(corewar_t *corewar)
{
    while (is_alive(corewar->champions) == OK) {
        execute_champion(corewar);
    }
    return OK;
}
