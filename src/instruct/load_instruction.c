/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** load_instruction
*/

#include "my.h"

static int *ld_init(corewar_t *corewar, champion_t **champion,
    instruct_types_t *types, int prog_nbr)
{
    if (!types)
        return NULL;
    champion[prog_nbr]->cycle_to_wait += op_tab[LD].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry = change_carry(champion, prog_nbr);
    return parse_parameter(corewar, types, LD, champion);
}

static int *lld_init(corewar_t *corewar, champion_t **champion,
    instruct_types_t *types, int prog_nbr)
{
    if (!types)
        return NULL;
    champion[prog_nbr]->cycle_to_wait += op_tab[LLD].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry = change_carry(champion, prog_nbr);
    return parse_parameter(corewar, types, LLD, champion);
}

int ld_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint32_t load = 0;

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    args = ld_init(corewar, champion, types, prog_nbr);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        load = args[0];
    } else if (types[0] == INDIRECT)
        load = *((uint32_t *)my_uint8_ndup
            (&corewar->arena[champion[prog_nbr]->current_PC + args[0]
            % IDX_MOD], REG_SIZE));
    champion[prog_nbr]->regs[args[1]] = load;
    free(args);
    free(types);
    return OK;
}

int lld(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint32_t load = 0;

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    args = lld_init(corewar, champion, types, prog_nbr);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        load = args[0];
    } else if (types[0] == INDIRECT)
        load = *((uint32_t *)my_uint8_ndup
            (&corewar->arena[champion[prog_nbr]->current_PC + args[0]],
            REG_SIZE));
    champion[prog_nbr]->regs[args[1]] = load;
    free(args);
    free(types);
    return OK;
}

static void ldi_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    uint32_t load = 0;

    for (int i = 0; i < 2; i += 1) {
        if (types[i] == REGISTER)
            load += corewar->champions[prog_nbr]->regs[args[i]];
        if (types[i] == DIRECT)
            load += args[i];
        if (types[i] == INDIRECT)
            load += *((uint32_t *)my_uint8_ndup
            (&corewar->arena[corewar->champions[prog_nbr]->current_PC +
            args[i] % IDX_MOD], IND_SIZE));
    }
    corewar->champions[prog_nbr]->regs[args[2]] = *((uint32_t *)my_uint8_ndup
            (&corewar->arena[corewar->champions[prog_nbr]->current_PC +
            load % IDX_MOD], REG_SIZE));
}

int ldi(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[LDI].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry = change_carry(champion, prog_nbr);
    args = parse_parameter(corewar, types, LDI, champion);
    if (!args)
        return KO;
    ldi_loop(corewar, args, types, prog_nbr);
    free(args);
    free(types);
    return OK;
}

static void lldi_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    uint32_t load = 0;

    for (int i = 0; i < 2; i += 1) {
        if (types[i] == REGISTER)
            load += corewar->champions[prog_nbr]->regs[args[i]];
        if (types[i] == DIRECT)
            load += args[i];
        if (types[i] == INDIRECT)
            load += *((uint32_t *)my_uint8_ndup
            (&corewar->arena[corewar->champions[prog_nbr]->current_PC +
            args[i]], IND_SIZE));
    }
    corewar->champions[prog_nbr]->regs[args[1]] = *((uint32_t *)my_uint8_ndup
            (&corewar->arena[corewar->champions[prog_nbr]->current_PC +
            load], REG_SIZE));
}

int lldi(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[LLDI].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry = change_carry(champion, prog_nbr);
    args = parse_parameter(corewar, types, LLDI, champion);
    if (!args)
        return KO;
    lldi_loop(corewar, args, types, prog_nbr);
    free(args);
    free(types);
    return OK;
}
