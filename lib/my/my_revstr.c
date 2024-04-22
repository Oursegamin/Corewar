/*
** EPITECH PROJECT, 2023
** revstr
** File description:
** Task03
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int temp = 0;
    int nb = 0;

    while (nb < len) {
        temp = str[len];
        str[len] = str[nb];
        str[nb] = temp;
        nb += 1;
        len -= 1;
    }
    return (str);
}
