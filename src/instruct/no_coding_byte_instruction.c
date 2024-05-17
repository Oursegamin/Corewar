/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** no_coding_byte_instruction
*/

#include "my.h"

static void print_live(champion_t *champion)
{
    my_putstr("The player ");
    my_putnbr(champion->prog_number);
    my_putchar('(');
    my_putstr(champion->prog_name);
    my_putstr(")is alive.\n");
}

static void init_new_champ(champion_t ***champion, int prog_nbr,
    int pc, int len)
{
    (*champion)[len - 1]->is_alive = true;
    (*champion)[len - 1]->cycle_to_die = CYCLE_TO_DIE;
    (*champion)[len - 1]->prog_name =
        my_strdup((*champion)[prog_nbr]->prog_name);
    (*champion)[len - 1]->prog_number = (*champion)[prog_nbr]->prog_number;
    (*champion)[len - 1]->prog_size = (*champion)[prog_nbr]->prog_size;
    (*champion)[len - 1]->instructions = NULL;
    (*champion)[len - 1]->pc = pc;
    (*champion)[len - 1]->load_address = (*champion)[prog_nbr]->load_address;
    (*champion)[len - 1]->current_pc = pc;
    for (int i = 0; i < REG_NUMBER; i++)
        (*champion)[len - 1]->regs[i] = (*champion)[prog_nbr]->regs[i];
    (*champion)[len - 1]->cycle_to_wait = (*champion)[prog_nbr]->cycle_to_wait;
    (*champion)[len - 1]->carry = (*champion)[prog_nbr]->carry;
}

static int dup_champ_fork(champion_t ***champion, int prog_nbr, int pc)
{
    int len = 0;

    for (; (*champion)[len]; len += 1);
    len += 1;
    (*champion) = realloc(*champion, sizeof(champion_t *) * (len + 1));
    if (!champion)
        return KO;
    (*champion)[len - 1] = malloc(sizeof(champion_t));
    if (!(*champion)[len - 1])
        return KO;
    (*champion)[len] = NULL;
    init_new_champ(champion, prog_nbr, pc, len);
    return OK;
}

int live(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types = get_instruct_types
        (corewar->arena[(*champion)[prog_nbr]->pc + 1], LIVE);

    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LIVE].nbr_cycles;
    (*champion)[prog_nbr]->pc += 1;
    args = parse_parameter(corewar, types, LIVE, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    print_live((*champion)[prog_nbr]);
    (*champion)[prog_nbr]->cycle_to_die = CYCLE_TO_DIE;
    corewar->current_nbr_live += 1;
    free(args);
    free(types);
    return OK;
}

int zjmp(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types = get_instruct_types
        (corewar->arena[(*champion)[prog_nbr]->pc + 1], ZJMP);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[ZJMP].nbr_cycles;
    (*champion)[prog_nbr]->pc += 1;
    args = parse_parameter(corewar, types, ZJMP, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    if ((*champion)[prog_nbr]->carry == 1 && types[0] == DIRECT)
        (*champion)[prog_nbr]->pc = (*champion)[prog_nbr]->current_pc +
            args[0] % IDX_MOD;
    free(args);
    free(types);
    return corewar->arena[corewar->champions[prog_nbr]->pc] <= 16 &&
        corewar->arena[corewar->champions[prog_nbr]->pc] >= 1 ? OK : KO;
}

int fork_i(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types = get_instruct_types
        (corewar->arena[(*champion)[prog_nbr]->pc + 1], FORK);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[FORK].nbr_cycles;
    (*champion)[prog_nbr]->pc += 1;
    args = parse_parameter(corewar, types, FORK, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    if (types[0] == DIRECT && dup_champ_fork(champion, prog_nbr,
        (*champion)[prog_nbr]->current_pc + args[0] % IDX_MOD) == KO) {
        free(args);
        return KO;
    }
    free(args);
    free(types);
    return OK;
}

int lfork(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types = get_instruct_types
        (corewar->arena[(*champion)[prog_nbr]->pc + 1], LFORK);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[LFORK].nbr_cycles;
    (*champion)[prog_nbr]->pc += 1;
    args = parse_parameter(corewar, types, LFORK, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    if (types[0] == DIRECT && dup_champ_fork(champion, prog_nbr,
        (*champion)[prog_nbr]->current_pc + args[0]) == KO) {
        free(args);
        return KO;
    }
    free(types);
    free(args);
    return OK;
}
