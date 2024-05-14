/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** change_carry
*/

#include "my.h"

bool change_carry(champion_t **champion, int prog_nbr)
{
    return champion[prog_nbr]->carry == false ? true : false;
}
