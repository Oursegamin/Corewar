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

static void dup_champ_fork(champion_t ***champion, int prog_nbr, int PC)
{
    int len = 0;

    for (; (*champion)[len]; len += 1);
    len += 1;
    (*champion) = realloc(*champion, sizeof(champion_t) * (len + 1));
    (*champion)[len] = NULL;
    (*champion)[len - 1]->is_alive = true;
    (*champion)[len - 1]->cycle_to_die = CYCLE_TO_DIE;
    (*champion)[len - 1]->prog_name =
        my_strdup((*champion)[prog_nbr]->prog_name);
    (*champion)[len - 1]->prog_number = (*champion)[prog_nbr]->prog_number;
    (*champion)[len - 1]->prog_size = 0;
    (*champion)[len - 1]->instructions = NULL;
    (*champion)[len - 1]->PC = PC;
    (*champion)[len - 1]->current_PC = PC;
    (*champion)[len - 1]->regs[0] = (*champion)[prog_nbr]->prog_number;
    for (int i = 1; i < REG_NUMBER; i++)
        (*champion)[len - 1]->regs[i] = 0;
    (*champion)[len - 1]->cycle_to_wait = 0;
    (*champion)[len - 1]->carry = 0;
}

int live(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[LIVE].nbr_cycles;
    champion[prog_nbr]->PC += 1;
    args = parse_parameter(corewar, types, LIVE, champion);
    if (!args)
        return KO;
    print_live(champion[prog_nbr]);
    champion[prog_nbr]->cycle_to_die = CYCLE_TO_DIE;
    corewar->current_nbr_live += 1;
    free(args);
    free(types);
    return OK;
}

int zjmp(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[ZJMP].nbr_cycles;
    champion[prog_nbr]->PC += 1;
    args = parse_parameter(corewar, types, ZJMP, champion);
    if (!args)
        return KO;
    if (champion[prog_nbr]->carry == 1 && types[0] == DIRECT)
        champion[prog_nbr]->PC = champion[prog_nbr]->current_PC +
            args[0] % IDX_MOD;
    free(args);
    free(types);
    return OK;
}

int fork_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[FORK].nbr_cycles;
    champion[prog_nbr]->PC += 1;
    args = parse_parameter(corewar, types, FORK, champion);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        dup_champ_fork(&champion, prog_nbr, champion[prog_nbr]->current_PC +
            args[0] % IDX_MOD);
    }
    free(args);
    free(types);
    return OK;
}

int lfork(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[champion[prog_nbr]->PC + 1]);

    champion[prog_nbr]->current_PC = champion[prog_nbr]->PC;
    if (!types)
        return KO;
    champion[prog_nbr]->cycle_to_wait += op_tab[LFORK].nbr_cycles;
    champion[prog_nbr]->PC += 1;
    args = parse_parameter(corewar, types, LFORK, champion);
    if (!args)
        return KO;
    if (types[0] == DIRECT) {
        dup_champ_fork(&champion, prog_nbr, champion[prog_nbr]->current_PC +
            args[0]);
    }
    free(args);
    free(types);
    return OK;
}
