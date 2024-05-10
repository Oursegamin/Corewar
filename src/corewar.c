/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** corewar
*/

#include "my.h"

static int count_progs(int argc, char const *const *argv)
{
    int nb = 0;

    for (int i = 1; i < argc; i++) {
        if (!argv[i])
            return -KO;
        if (argv[i][0] == '-') {
            i += 1;
            continue;
        }
        if (argv[i][0] != '-')
            nb += 1;
    }
    if (nb >= 2 && nb <= 4)
        return nb;
    return -KO;
}

static int malloc_corewar(int argc, char const *const *argv,
    corewar_t *corewar)
{
    int prog_nbrs = count_progs(argc, argv);

    if (prog_nbrs == -KO)
        return KO;
    corewar->champions = malloc(sizeof(champion_t *) * (prog_nbrs + 1));
    if (!corewar->champions)
        return KO;
    for (int i = 0; i < prog_nbrs; i++) {
        corewar->champions[i] = malloc(sizeof(champion_t));
        if (!corewar->champions[i])
            return KO;
        corewar->champions[i]->is_alive = true;
        corewar->champions[i]->PC = -1;
        corewar->champions[i]->nbr_cycle = 0;
        corewar->champions[i]->prog_number = -1;
        corewar->champions[i]->load_address = -1;
        corewar->champions[i]->carry = false;
    }
    corewar->champions[prog_nbrs] = NULL;
    return OK;
}

int launch_war(int argc, char const *const *argv)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (!argv)
        return KO;
    if (malloc_corewar(argc, argv, corewar) == KO)
        return KO;
    if (parse_war_progs(corewar, argc, argv) == KO)
        return KO;
    if (load_in_arena(corewar) == KO)
        return KO;
    return OK;
}
