/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myhunter-florian.labadie
** File description:
** int_to_char
*/

#include "../../include/my.h"
#include <stdlib.h>

int intlen(int nbr)
{
    int count = 0;

    while (nbr != 0) {
        nbr = nbr / 10;
        count += 1;
    }
    return count;
}

char *int_to_str(int nbr)
{
    char *str = malloc(sizeof(char) * (intlen(nbr) + 1));
    int tmp = nbr;
    int i = 0;

    if (nbr == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while (tmp != 0) {
        str[i] = (tmp % 10) + '0';
        tmp = tmp / 10;
        i += 1;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
