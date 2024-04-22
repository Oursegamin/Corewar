/*
** EPITECH PROJECT, 2023
** strncmp
** File description:
** pasfais
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2)
        return KO;
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return OK;
}
