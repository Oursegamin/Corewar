/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** load_in_arena
*/

#include "my.h"

static void loadchamp(champion_t **champions, uint8_t arena[])
{
    size_t size_in_arena = 0;
    size_t remaining_size = 0;

    if ((*champions)->pc + (*champions)->prog_size > MEM_SIZE) {
        size_in_arena = MEM_SIZE - (*champions)->pc;
        my_memcpy(arena + (*champions)->pc,
            (*champions)->instructions, size_in_arena);
        remaining_size = (*champions)->prog_size - size_in_arena;
        my_memcpy(arena, (*champions)->instructions + size_in_arena,
            remaining_size);
    } else {
        my_memcpy(arena + (*champions)->pc,
            (*champions)->instructions, (*champions)->prog_size);
    }
}

static int calculate_padding(corewar_t *corewar)
{
    int i = 0;
    int n = 0;
    int padding = 0;

    if (!corewar)
        return -KO;
    for (; corewar->champions[i] != NULL; i += 1) {
        n += corewar->champions[i]->prog_size;
    }
    padding = (MEM_SIZE - n) / (i + 1);
    return padding;
}

static void found_space(init_area_t *area)
{
    if (!area->check_space && area->padding > 0) {
        if (area->current_address == 0) {
            area->next_address = area->current_address + (area->padding / 2);
        } else
            area->next_address = area->current_address + area->padding;
        area->check_space = true;
    }
}

static void load_adress(corewar_t *corewar, int *i, init_area_t *area)
{
    if (corewar->champions[*i]->pc != -1) {
        loadchamp(&corewar->champions[*i], corewar->arena);
        area->current_address = corewar->champions[*i]->pc +
            corewar->champions[*i]->prog_size;
    }
}

static void check_next_champ(corewar_t *corewar, init_area_t *area, int *i)
{
    for (size_t j = *i + 1; corewar->champions[j] != NULL; j += 1) {
        if (corewar->champions[j]->pc > area->current_address) {
            area->next_address = corewar->champions[j]->pc + area->padding;
            area->check_space = true;
            break;
        }
    }
}

static void no_load_adress(corewar_t *corewar, init_area_t *area, int *i)
{
    load_adress(corewar, i, area);
    if (corewar->champions[*i]->pc == -1) {
        area->check_space = false;
        check_next_champ(corewar, area, i);
        found_space(area);
        corewar->champions[*i]->pc = area->next_address % MEM_SIZE;
        loadchamp(&corewar->champions[*i], corewar->arena);
        area->current_address = area->next_address +
            corewar->champions[*i]->prog_size;
    }
}

int load_in_arena(corewar_t *corewar)
{
    init_area_t *area = malloc(sizeof(init_area_t));

    area->padding = calculate_padding(corewar);
    area->check_space = false;
    area->current_address = 0;
    area->next_address = 0;
    if (area->padding == -KO || !area)
        return KO;
    for (int i = 0; corewar->champions[i] != NULL; i += 1) {
        no_load_adress(corewar, area, &i);
        corewar->champions[i]->load_address = corewar->champions[i]->pc;
    }
    return OK;
}
