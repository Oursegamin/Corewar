/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** cond_instruction
*/

#include "my.h"

int add(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->nbr_cycle += op_tab[ADD].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry =
        champion[prog_nbr]->carry == false ? true : false;
    args = parse_parameter(corewar, types, ADD, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = args[0] + args[1];
    free(args);
    return OK;
}

int sub(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->nbr_cycle += op_tab[SUB].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, SUB, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = args[0] - args[1] < 0 ?
        -(args[0] - args[1]) : args[0] - args[1];
    free(args);
    return OK;
}

int and_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->nbr_cycle += op_tab[AND].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    champion[prog_nbr]->carry =
        champion[prog_nbr]->carry == false ? true : false;
    args = parse_parameter(corewar, types, AND, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = args[0] & args[1];
    free(args);
    return OK;
}

int or_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->nbr_cycle += op_tab[OR].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, OR, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = args[0] | args[1];
    free(args);
    return OK;
}

int xor_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->nbr_cycle += op_tab[XOR].nbr_cycles;
    champion[prog_nbr]->PC += 2;
    args = parse_parameter(corewar, types, XOR, champion);
    if (!args)
        return KO;
    champion[prog_nbr]->regs[args[2]] = args[0] ^ args[1];
    free(args);
    return OK;
}
