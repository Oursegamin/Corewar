/*
** EPITECH PROJECT, 2023
** day08
** File description:
** task01
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;

    if (!src)
        return NULL;
    str = malloc(my_strlen(src) + 1);
    my_strcpy(str, src);
    return (str);
}
