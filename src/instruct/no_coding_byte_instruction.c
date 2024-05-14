/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** no_coding_byte_instruction
*/

#include "my.h"

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
    my_putstr("The player ");
    my_putnbr(champion[prog_nbr]->prog_number);
    my_putchar('(');
    my_putstr(champion[prog_nbr]->prog_name);
    my_putstr(")is alive.\n");
    champion[prog_nbr]->cycle_to_die = CYCLE_TO_DIE;
    corewar->current_nbr_live += 1;
    free(args);
    return OK;
}

int zjmp(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    return OK;
}

int fork_i(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    return OK;
}

int lfork(corewar_t *corewar, champion_t **champion, int prog_nbr)
{
    return OK;
}
