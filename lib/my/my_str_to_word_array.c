/*
** EPITECH PROJECT, 2023
** Projet-Unix
** File description:
** my_str_to_word_array
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../../include/my.h"

static int array_len(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\n'; i += 1) {
        count += 1;
    }
    return count;
}

char **my_str_to_word_array(char *str)
{
    char **array;
    int col = 0;
    int line = 0;

    array = malloc(sizeof(char *) * (array_len(str) + 1));
    for (int i = 0; str[i] != '\0'; i += 1) {
        array[col] = malloc(sizeof(char) * (i + 1));
        line += 1;
        if (str[i] == '\n') {
            my_strncpy(array[col], str, i + 1);
            col += 1;
            str = &str[i + 1];
            i = 0;
        }
        array[col] = NULL;
    }
    return array;
}
