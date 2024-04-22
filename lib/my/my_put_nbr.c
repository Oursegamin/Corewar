/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** pasfais
*/

#include "../../include/my.h"
#include <stdio.h>

int my_put_nbr(int nb)
{
    int count = 1;
    int tmp = nb;

    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
        count = count + 1;
        tmp = -tmp;
    }
    while (tmp / 10 > 0) {
        tmp = tmp / 10;
        count = count + 1;
    }
    if (nb % 10 != nb) {
        my_put_nbr((nb - (nb % 10)) / 10);
        my_putchar(48 + (nb % 10));
    } else {
        my_putchar(48 + nb);
    }
    return (count);
}
