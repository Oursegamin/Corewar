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
    for (int i = NO_MORE_TYPE - 1; i >= 0; i--) {
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
