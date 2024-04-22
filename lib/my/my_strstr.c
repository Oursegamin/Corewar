/*
** EPITECH PROJECT, 2023
** strstr
** File description:
** pasfais
*/

#include "my.h"

char *my_strstr(char const *str, char const *needle)
{
    int len = my_strlen(str);
    int needle_len = my_strlen(needle);

    if (!str || !needle)
        return NULL;
    for (int i = 0; i < len - needle_len - 1; i += 1) {
        if (my_strncmp(&str[i], needle, needle_len) == OK) {
            my_strndup(needle, needle_len);
            return my_strndup(&str[i], needle_len);
        }
    }
    return NULL;
}
