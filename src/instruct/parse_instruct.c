/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** parse_instruction
*/

#include "my.h"

static void add_types(instruct_types_t **types,
    instruct_types_t type, int *len)
{
    *len += 1;
    (*types) = realloc(*types, sizeof(instruct_types_t) * (*len + 1));
    (*types)[*len - 1] = type;
    (*types)[*len] = NO_MORE_TYPE;
}

instruct_types_t *get_instruct_types(uint8_t coding_byte)
{
    int len = 0;
    instruct_types_t *types = malloc(sizeof(instruct_types_t) * (len + 1));
    int bits = 0;

    types[0] = NO_MORE_TYPE;
    for (int i = INSTRUCT_TYPES_SIZE - 1; i >= 0; i--) {
        bits = (coding_byte >> 2 * i) & 3;
        if (bits == 0)
            break;
        if (bits == REGISTER)
            add_types(&types, REGISTER, &len);
        if (bits == DIRECT)
            add_types(&types, DIRECT, &len);
        if (bits == INDIRECT)
            add_types(&types, INDIRECT, &len);
    }
    return types;
}

static int get_direct_types(corewar_t *corewar, instruct_types_t *types,
    instructions_t instruct, champion_t **champion)
{
    return -KO;
}

static int types_checker(corewar_t *corewar, instruct_types_t *types,
    instructions_t instruct, champion_t **champion)
{
    if (*types == REGISTER) {
        (*champion)->PC += 1;
        if ((*champion)->regs[corewar->arena[(*champion)->PC - 1]] < 1 ||
            (*champion)->regs[corewar->arena[(*champion)->PC - 1]] > 16)
            *types = INSTRUCT_TYPES_SIZE;
        return (int)(*champion)->regs[corewar->arena[(*champion)->PC - 1]];
    }
    if (*types == INDIRECT) {
        (*champion)->PC += 2;
        return (int)my_strndup(corewar->arena[(*champion)->PC - 2],
                                IND_SIZE);
    }
    if (*types == DIRECT) {
        (*champion)->PC += 2; // fonction pour savoir si c'est 2 ou 4 BYTES
        return (int)my_strndup(corewar->arena[(*champion)->PC - 2],
                                DIR_SIZE);
    }
    *types = INSTRUCT_TYPES_SIZE;
    return -KO;
}

int *parse_parameter(corewar_t *corewar, instruct_types_t *types,
    instructions_t instruct, champion_t **champion)
{
    int *args = malloc(sizeof(int) + op_tab[instruct].nbr_args);

    for (int i = 0; i < op_tab[instruct].nbr_args; i++) {
        args[i] = types_checker(corewar, &types[i], instruct, champion);
        if (types[i] == INSTRUCT_TYPES_SIZE) {
            free(args);
            return NULL;
        }
    }
    return args;
}
