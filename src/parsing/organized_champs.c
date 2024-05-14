/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** organized_champs
*/

#include "my.h"

static int check_champions_info(champion_t **cs, int prog_number, int i)
{
    for (int j = i + 1; cs[j]; j++) {
        if (prog_number == cs[j]->prog_number)
            return OK;
    }
    return KO;
}

static int check_champions(champion_t **champions)
{
    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->prog_number >= 1 && check_champions_info
                (champions, champions[i]->prog_number, i) == OK)
            return KO;
    }
    return OK;
}

int organized_champions(champion_t ***champions, int champs_nbr)
{
    int number = 0;

    if (check_champions(*champions) == KO)
        return KO;
    for (int i = 0; i < champs_nbr; i++) {
        if ((*champions)[i]->prog_number >= 1)
            continue;
        while (check_champions_info(*champions, number, 0) == OK)
            number += 1;
        (*champions)[i]->prog_number = number;
        number += 1;
    }
    sort_champions(champions);
    for (int i = 0; i < champs_nbr; i++)
        (*champions)[i]->regs[0] = (*champions)[i]->prog_number;
    return OK;
}
