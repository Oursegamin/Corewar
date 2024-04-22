/*
** EPITECH PROJECT, 2023
** day07
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (!s1 || !s2)
        return KO;
    len = len > len2 ? len : len2;
    for (int i = 0; i < len; i++) {
        if (s1[i] < s2[i])
            return ERR;
        if (s1[i] > s2[i])
            return ERR;
    }
    return OK;
}
