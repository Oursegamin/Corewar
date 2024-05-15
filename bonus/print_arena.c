/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** print_arena
*/

#include "my.h"
#include <ncurses.h>

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

static int cycle_delta(corewar_t *corewar)
{
    int cycle_to_remove = CYCLE_DELTA * corewar->current_nbr_live / 40;

    if (cycle_to_remove <= 0)
        return 1;
    return cycle_to_remove;
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

static void print_arena_in_real_time(corewar_t *corewar)
{
    int row = 0;
    int col = 0;

    clear();
    for (int i = 0; i < MEM_SIZE; i++) {
        mvprintw(row, col * 3, "%02x", (unsigned char)corewar->arena[i]);
        col++;
        if (col >= 80) {
            col = 0;
            row++;
        }
    }
    refresh();
    // usleep(50000);
}

int champion_arena(corewar_t *corewar)
{
    initscr();
    cbreak();
    noecho();
    while (is_alive(corewar->champions) == OK) {
        execute_champion(corewar);
        print_arena_in_real_time(corewar);
    }
    for (int i = 0; corewar->champions[i] != NULL; i++) {
        if (corewar->champions[i]->is_alive == true) {
            my_putstr("The player ");
            my_putnbr(corewar->champions[i]->prog_number);
            my_putchar('(');
            my_putstr(corewar->champions[i]->prog_name);
            my_putstr(")has won.\n");
            break;
        }
    }
    endwin();
    return OK;
}
