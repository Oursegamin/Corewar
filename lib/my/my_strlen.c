/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Task03
*/

#include "my.h"

int my_strlen(char const *str)
{
    int a = 0;

    if (str == NULL)
        return 0;
    while (str[a] != '\0') {
        a += 1;
    }
    return (a);
}
