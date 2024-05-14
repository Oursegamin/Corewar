/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** parse_param_from_arena
*/

#include "my.h"

static uint32_t get_intstruct_length(instruct_types_t *types,
    instructions_t instruct)
{
    int len = 1;

    if (instruct != LIVE && instruct != ZJMP &&
        instruct != FORK && instruct != LFORK)
        len += 1;
    for (int i = 0; types != NO_MORE_TYPE; i++) {
        if (types[i] == REGISTER)
            len += T_REG;
        if (types[i] == INDIRECT)
            len += IND_SIZE;
        if (types[i] == DIRECT)
            len += DIR_SIZE;
    }
    return len;
}

static uint32_t check_direct_size(instruct_types_t *types,
    instructions_t instruct)
{
    uint32_t len = 0;

    if (instruct == AND || instruct == OR || instruct == XOR)
        return DIR_SIZE;
    len = get_intstruct_length(types, instruct);
    if (len > 7)
        return DIR_SIZE / 2;
    return DIR_SIZE;
}

static uint32_t get_register_value(corewar_t *corewar, instruct_types_t *types,
    champion_t **champion)
{
    uint8_t reg = 0;

    if (corewar->arena[(*champion)->PC] < 1 ||
        corewar->arena[(*champion)->PC] > 16) {
        *types = NO_MORE_TYPE;
        return reg;
    }
    reg = (uint8_t)corewar->arena[(*champion)->PC];
    (*champion)->PC = ((*champion)->PC + T_REG) % MEM_SIZE;
    if (reg > 16 || reg < 1)
        *types = NO_MORE_TYPE;
    return (uint32_t)reg;
}

static uint32_t get_indirect_value(corewar_t *corewar, champion_t **champion)
{
    uint16_t *ind = NULL;

    if ((*champion)->PC + IND_SIZE < MEM_SIZE)
        ind = (uint16_t *)my_uint8_ndup(&corewar->arena[(*champion)->PC],
            IND_SIZE);
    (*champion)->PC = ((*champion)->PC + IND_SIZE) % MEM_SIZE;
    return *ind;
}

static uint32_t get_direct_value(corewar_t *corewar, int param_size,
    champion_t **champion)
{
    uint16_t *short_dir = NULL;
    uint32_t *int_dir = NULL;

    if ((*champion)->PC + param_size < MEM_SIZE) {
        if (param_size == DIR_SIZE / 2) {
            short_dir = (uint16_t *)my_uint8_ndup
                (&corewar->arena[(*champion)->PC], param_size);
            (*champion)->PC = ((*champion)->PC + param_size) % MEM_SIZE;
            return (uint32_t)*short_dir;
        } else {
            int_dir = (uint32_t *)my_uint8_ndup
                (&corewar->arena[(*champion)->PC], param_size);
        }
    }
    (*champion)->PC = ((*champion)->PC + param_size) % MEM_SIZE;
    return *int_dir;
}

static int types_checker(corewar_t *corewar, instruct_types_t *types,
    champion_t **champion)
{
    if (*types == REGISTER)
        return get_register_value(corewar, types, champion);
    if (*types == INDIRECT)
        return get_indirect_value(corewar, champion);
    *types = NO_MORE_TYPE;
    return -KO;
}

int *parse_parameter(corewar_t *corewar, instruct_types_t *types,
    instructions_t instruct, champion_t **champion)
{
    int *args = malloc(sizeof(int) + op_tab[instruct].nbr_args);
    int direct_length = 0;

    for (int i = 0; i < op_tab[instruct].nbr_args; i++) {
        if (types[i] == DIRECT) {
            direct_length = check_direct_size(types, instruct);
            args[i] = get_direct_value(corewar, direct_length, champion);
        } else
            args[i] = types_checker(corewar, &types[i], champion);
        if (types[i] == NO_MORE_TYPE) {
            free(args);
            return NULL;
        }
    }
    return args;
}
