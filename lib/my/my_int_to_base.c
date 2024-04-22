/*
** EPITECH PROJECT, 2023
** TAsk 18 D06
** File description:
** Base
*/

#include "my.h"

void alpha(int a, char *str, int *i)
{
    if (a > 9) {
        a = a - 10;
        str[*i] = a + 97;
    }
}

char *my_int_to_base(unsigned long nbr, int base)
{
    int a = 0;
    char *str = malloc(sizeof(char) * 32);
    int i = 0;

    if (nbr == 0)
        return "0";
    str[0] = '\0';
    for (; nbr != 0; i += 1) {
        a = nbr % base;
        nbr = nbr / base;
        if (a <= 9) {
            str[i] = a + 48;
        }
        alpha(a, str, &i);
        str[i + 1] = '\0';
    }
    my_revstr(str);
    return str;
}
