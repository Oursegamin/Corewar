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
        if (champion[j]->is_alive && champion[j]->prog_number == prog_nbr)
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

static void print_champs_status(champion_t **champion)
{
    for (int i = 0; champion[i] != NULL; i++) {
        if (champion[i]->is_alive == true &&
            check_already_alive(champion, champion[i]->prog_number, i) != OK) {
            my_putstr("The player ");
            my_putnbr(champion[i]->prog_number);
            my_putchar('(');
            my_putstr(champion[i]->prog_name);
            my_putstr(")is alive.\n");
        } else {
            my_putstr("The player ");
            my_putnbr(champion[i]->prog_number);
            my_putchar('(');
            my_putstr(champion[i]->prog_name);
            my_putstr(")is not alive.\n");
        }
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
        if (corewar->champions[i]->cycle_to_die >= corewar->cycle_to_die)
            corewar->champions[i]->is_alive = false;
        if (!corewar->champions[i]->is_alive)
            continue;
        corewar->champions[i]->cycle_to_die += 1;
        corewar->cycle_to_die -= cycle_delta(corewar);
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
    }
}

static void initialize_colors(corewar_t *corewar)
{
    int j = 0;

    for (; j < corewar->champs_nbr; j++) {
        init_pair(corewar->champions[j]->prog_number, COLOR_GREEN +
            (corewar->champions[j]->prog_number - 1), COLOR_BLACK);
    }
    init_pair(10, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(11, COLOR_WHITE, COLOR_RED);
}

static void set_colors(corewar_t *corewar, int *i, int *color, int *size)
{
    for (int j = 0; corewar->champions[j] != NULL; j++) {
        if (corewar->champions[j]->load_address +
            corewar->champions[j]->prog_size > MEM_SIZE) {
            *size = (corewar->champions[j]->load_address +
                corewar->champions[j]->prog_size) - MEM_SIZE;
        } else
            *size = 0;
        if ((j < corewar->champs_nbr && (*i >= corewar->champions[j]->load_address &&
            *i < corewar->champions[j]->load_address +
            corewar->champions[j]->prog_size)) || *i < *size) {
            *color = corewar->champions[j]->prog_number;
        }
        if (*i == corewar->champions[j]->pc && corewar->champions[j]->is_alive == true)
            *color = 10;
        if (*i == corewar->champions[j]->pc && corewar->champions[j]->is_alive == false)
            *color = 11;
    }
}

static void print_arena_in_real_time(corewar_t *corewar)
{
    int color = 0;
    int size = 0;

    clear();
    mvprintw(0, (COLS - 15) / 2, "Cycle count: %d", corewar->nbr_of_cycles);
    mvprintw(1, (COLS - 15) / 2, "Cycle to die: %d", corewar->cycle_to_die);
    for (int i = 0; i < MEM_SIZE; i++) {
        color = 0;
        set_colors(corewar, &i, &color, &size);
        if (color) {
            attron(COLOR_PAIR(color));
            mvprintw(i / 90 + 2, (i % 90) * 3, "%02X", corewar->arena[i]);
            attroff(COLOR_PAIR(color));
        } else {
            mvprintw(i / 90 + 2, (i % 90) * 3, "%02X", corewar->arena[i]);
        }
    }
    refresh();
    usleep(10000);
}

int champion_arena(corewar_t *corewar)
{
    int dump_stop = 0;

    initscr();
    cbreak();
    noecho();
    start_color();
    initialize_colors(corewar);
    while (is_alive(corewar->champions) == OK) {
        print_arena_in_real_time(corewar);
        execute_champion(corewar);
        corewar->nbr_of_cycles += 1;
        if (corewar->nbr_of_cycles == corewar->dump) {
            print_champs_status(corewar->champions);
            dump_stop = 1;
            break;
        }
    }
    print_arena_in_real_time(corewar);
    usleep(1000000);
    endwin();
    end_game(corewar->champions, dump_stop);
    return OK;
}
