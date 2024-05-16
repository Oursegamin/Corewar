/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** arena
*/

#include "my.h"

static int (*intructions[16])(corewar_t *, champion_t ***, int) = {
    live,
    ld_i,
    st_i,
    add,
    sub,
    and_i,
    or_i,
    xor_i,
    zjmp,
    ldi,
    sti,
    fork_i,
    lld,
    lldi,
    lfork,
    aff
};

static int check_already_alive(champion_t **champion, int prog_nbr, int i)
{
    for (int j = i - 1; j >= 0; j--) {
        if (champion[j]->prog_number == prog_nbr)
            return OK;
    }
    return KO;
}

static int is_alive(champion_t **champion)
{
    int end = 0;

    for (int i = 0; champion[i] != NULL; i++) {
        if (champion[i]->is_alive == true &&
            check_already_alive(champion, champion[i]->prog_number, i) != OK)
            end += 1;
    }
    if (end == 1)
        return KO;
    return OK;
}

static void end_game(champion_t **champion, int dump_stop)
{
    for (int i = 0; dump_stop == 0 && champion[i] != NULL; i++) {
        if (champion[i]->is_alive == true) {
            my_putstr("The player ");
            my_putnbr(champion[i]->prog_number);
            my_putchar('(');
            my_putstr(champion[i]->prog_name);
            my_putstr(")has won.\n");
            break;
        }
    }
}

static void print_champs_status(corewar_t *corewar)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (corewar->arena[i] < 16)
            my_putchar('0');
        my_putstr(my_int_to_base(corewar->arena[i], 16));
        my_putchar(' ');
        if ((i + 1) % 32 == 0)
            my_putchar('\n');
    }
}

static int cycle_delta(corewar_t *corewar)
{
    if (corewar->current_nbr_live == 40) {
        corewar->current_nbr_live = 0;
        return CYCLE_DELTA;
    }
    return 0;
}

static void execute_champion(corewar_t *corewar)
{
    for (int i = 0; corewar->champions[i] != NULL; i++) {
        if (is_alive(corewar->champions) == KO)
            break;
        if (corewar->champions[i]->cycle_to_die <= 0)
            corewar->champions[i]->is_alive = false;
        if (!corewar->champions[i]->is_alive)
            continue;
        if (corewar->champions[i]->cycle_to_wait > 0) {
            corewar->champions[i]->cycle_to_wait -= 1;
            continue;
        }
        if (corewar->arena[corewar->champions[i]->pc] > 16 ||
            corewar->arena[corewar->champions[i]->pc] < 1 ||
            intructions[corewar->arena[corewar->champions[i]->pc] - 1]
            (corewar, &corewar->champions, i) == KO) {
            corewar->champions[i]->pc += 1;
        }
        corewar->champions[i]->cycle_to_die -= cycle_delta(corewar);
    }
}

int champion_arena(corewar_t *corewar)
{
    int dump_stop = 0;

    while (is_alive(corewar->champions) == OK) {
        execute_champion(corewar);
        corewar->nbr_of_cycles += 1;
        if (corewar->nbr_of_cycles == corewar->dump) {
            print_champs_status(corewar);
            dump_stop = 1;
            break;
        }
    }
    end_game(corewar->champions, dump_stop);
    return OK;
}
