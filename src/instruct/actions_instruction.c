/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** actions_instruction
*/

#include "my.h"

static void sti_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    uint32_t load = 0;

    for (int i = 1; i < 3; i += 1) {
        if (types[i] == REGISTER)
            load += corewar->champions[prog_nbr]->regs[args[i]];
        if (types[i] == DIRECT || types[i] == INDIRECT)
            load += args[i];
    }
    corewar->arena[corewar->champions[prog_nbr]->current_PC +
            load % IDX_MOD] = corewar->champions[prog_nbr]->regs[args[0]];
}

int st_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[ST].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, ST, champion);
    if (!args)
        return KO;
    if (types[1] == REGISTER)
        corewar->champions[prog_nbr]->regs[args[1]] =
            corewar->champions[prog_nbr]->regs[args[0]];
    if (types[1] == INDIRECT)
        corewar->arena[corewar->champions[prog_nbr]->current_PC +
            args[1] % IDX_MOD] = corewar->champions[prog_nbr]->regs[args[0]];
    free(args);
    return OK;
}

int sti(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[STI].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, STI, champion);
    if (!args)
        return KO;
    sti_loop(corewar, args, types, prog_nbr);
    free(args);
    return OK;
}

int aff(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint16_t aff = 0;

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[AFF].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, AFF, champion);
    if (!args)
        return KO;
    aff = corewar->champions[prog_nbr]->regs[args[0]] % (IDX_MOD / 2);
    my_putchar(aff);
    free(args);
    return OK;
}
