/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** load_instruction
*/

#include "my.h"

static int *ld_init(corewar_t *corewar, champion_t ***champion,
    instruct_types_t *types, int prog_nbr)
{
    if (!types)
        return NULL;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LD].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    return parse_parameter(corewar, types, LD, &(*champion)[prog_nbr]);
}

static int *lld_init(corewar_t *corewar, champion_t ***champion,
    instruct_types_t *types, int prog_nbr)
{
    if (!types)
        return NULL;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LLD].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    return parse_parameter(corewar, types, LLD, &(*champion)[prog_nbr]);
}

int ld_i(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], LD);
    int load = 0;

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    args = ld_init(corewar, champion, types, prog_nbr);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        load = args[0];
    } else if (types[0] == INDIRECT)
        load = *((int *)my_uint8_ndup(corewar->arena,
            (*champion)[prog_nbr]->current_pc + args[0] % IDX_MOD, REG_SIZE));
    (*champion)[prog_nbr]->regs[args[1] - 1] = load;
    (*champion)[prog_nbr]->carry =
        change_carry((*champion)[prog_nbr]->regs[args[1] - 1]);
    free(args);
    return OK;
}

int lld(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], LLD);
    int load = 0;

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    args = lld_init(corewar, champion, types, prog_nbr);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        load = args[0];
    } else if (types[0] == INDIRECT)
        load = *((int *)my_uint8_ndup(corewar->arena,
            (*champion)[prog_nbr]->current_pc + args[0], REG_SIZE));
    (*champion)[prog_nbr]->regs[args[1] - 1] = load;
    (*champion)[prog_nbr]->carry =
        change_carry((*champion)[prog_nbr]->regs[args[1] - 1]);
    free(args);
    return OK;
}

static void ldi_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    int *load = {0};

    for (int i = 0; i < 2; i += 1) {
        if (types[i] == REGISTER)
            *load += corewar->champions[prog_nbr]->regs[args[i] - 1];
        if (types[i] == DIRECT)
            *load += args[i];
        if (types[i] == INDIRECT)
            *load += *((int *)my_uint8_ndup
            (corewar->arena, corewar->champions[prog_nbr]->current_pc +
            args[i] % IDX_MOD, IND_SIZE));
    }
    corewar->champions[prog_nbr]->regs[args[2] - 1] = *((int *)my_uint8_ndup
            (corewar->arena, corewar->champions[prog_nbr]->current_pc +
            *load % IDX_MOD, REG_SIZE));
    free(load);
}

int ldi(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], LDI);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LDI].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    args = parse_parameter(corewar, types, LDI, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    ldi_loop(corewar, args, types, prog_nbr);
    (*champion)[prog_nbr]->carry =
        change_carry((*champion)[prog_nbr]->regs[args[2] - 1]);
    free(args);
    return OK;
}

static void lldi_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    int *load = {0};

    for (int i = 0; i < 2; i += 1) {
        if (types[i] == REGISTER)
            *load += corewar->champions[prog_nbr]->regs[args[i] - 1];
        if (types[i] == DIRECT)
            *load += args[i];
        if (types[i] == INDIRECT)
            *load += *((int *)my_uint8_ndup
            (corewar->arena, corewar->champions[prog_nbr]->current_pc +
            args[i], IND_SIZE));
    }
    corewar->champions[prog_nbr]->regs[args[2] - 1] = *((int *)my_uint8_ndup
            (corewar->arena, corewar->champions[prog_nbr]->current_pc +
            *load, REG_SIZE));
    free(load);
}

int lldi(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types = get_instruct_types
        (corewar->arena[((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], LLDI);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LLDI].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    args = parse_parameter(corewar, types, LLDI, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    lldi_loop(corewar, args, types, prog_nbr);
    (*champion)[prog_nbr]->carry =
        change_carry((*champion)[prog_nbr]->regs[args[2] - 1]);
    free(args);
    return OK;
}
