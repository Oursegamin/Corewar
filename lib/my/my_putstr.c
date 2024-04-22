/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Task02
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
    return a;
}
