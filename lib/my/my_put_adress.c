/*
** EPITECH PROJECT, 2023
** Flag p
** File description:
** Adress
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_put_adress(void *arg)
{
    void *a = arg;
    unsigned long b = (unsigned long)a;

    my_putstr("0x");
    my_put_nbr_base(b, 16, 0);
    return 0;
}
