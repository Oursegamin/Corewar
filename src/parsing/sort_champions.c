/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** sort_champions
*/

#include "my.h"

static int get_champion_size(champion_t *champion)
{
    int size = 0;

    size += sizeof(champion_t);
    size += my_strlen(champion->prog_name) + 1;
    size += champion->prog_size;
    return size;
}

static int is_sort(champion_t **champions)
{
    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->prog_number > champions[i + 1]->prog_number)
            return KO;
    }
    return OK;
}

static void sort(champion_t ***champions)
{
    for (int i = 0; (*champions)[i + 1]; i++) {
        if ((*champions)[i]->prog_number > (*champions)[i + 1]->prog_number)
            my_swap((*champions)[i], (*champions)[i + 1],
                get_champion_size((*champions)[i]),
                get_champion_size((*champions)[i + 1]));
    }
}

void sort_champions(champion_t ***champions)
{
    if (!*champions)
        return;
    while (is_sort(*champions) != OK)
        sort(champions);
}
