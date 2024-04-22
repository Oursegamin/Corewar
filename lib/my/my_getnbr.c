/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_get_nbr
*/

#include "my.h"

static void get(int *n, char const *str)
{
    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i += 1)
        *n = *n * 10 + (str[i] - '0');
}

int my_getnbr(char const *str)
{
    int n = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i += 1) {
        sign = str[i] == '-' ? sign * -1 : sign;
        if (str[i] >= '0' && str[i] <= '9') {
            get(&n, &str[i]);
            return n * sign;
        }
    }
    return OK;
}
