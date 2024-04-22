/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_put_in_array
*/

#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"

char **my_put_in_array(char **dest, char **src)
{
    for (int i = 0; src[i] != NULL; i += 1) {
        dest[i] = malloc(sizeof(char *) * (my_strlen(src[i]) + 1));
        dest[i] = src[i];
    }
    return dest;
}
