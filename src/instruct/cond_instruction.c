/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** cond_instruction
*/

#include "my.h"

static uint32_t *get_value_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    uint32_t *load = {0};

    for (int i = 0; i < 2; i += 1) {
        if (types[i] == REGISTER)
            load[i] = corewar->champions[prog_nbr]->regs[args[i]];
        if (types[i] == DIRECT)
            load[i] = args[i];
        if (types[i] == INDIRECT)
            load[i] = *((uint32_t *)my_uint8_ndup
            (&corewar->arena[corewar->champions[prog_nbr]->current_PC +
            args[i] % IDX_MOD], REG_SIZE));
    }
    return load;
}

int add(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[ADD].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry =
        champion[prog_nbr]->carry == false ? true : false;
    args = parse_parameter(corewar, types, ADD, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = champion[prog_nbr]->regs[args[0]] +
        champion[prog_nbr]->regs[args[1]];
    free(args);
    free(types);
    return OK;
}

int sub(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[SUB].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, SUB, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = champion[prog_nbr]->regs[args[0]] -
        champion[prog_nbr]->regs[args[1]];
    free(args);
    free(types);
    return OK;
}

int and_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint32_t *load = {0};

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[AND].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry =
        champion[prog_nbr]->carry == false ? true : false;
    args = parse_parameter(corewar, types, AND, champion);
    if (!args)
        return KO;
    load = get_value_loop(corewar, args, types, prog_nbr);
    corewar->champions[prog_nbr]->regs[args[2]] = load[0] & load[1];
    free(load);
    free(args);
    free(types);
    return OK;
}

int or_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint32_t *load = {0};

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[OR].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, OR, champion);
    if (!args)
        return KO;
    load = get_value_loop(corewar, args, types, prog_nbr);
    corewar->champions[prog_nbr]->regs[args[2]] = load[0] | load[1];
    free(load);
    free(args);
    free(types);
    return OK;
}

int xor_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);
    uint32_t *load = {0};

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[XOR].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, XOR, champion);
    if (!args)
        return KO;
    load = get_value_loop(corewar, args, types, prog_nbr);
    corewar->champions[prog_nbr]->regs[args[2]] = load[0] ^ load[1];
    free(load);
    free(args);
    free(types);
    return OK;
}
