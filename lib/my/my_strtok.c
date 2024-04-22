/*
** EPITECH PROJECT, 2024
** B-PSU-100-BDX-1-1-navy-florian.labadie
** File description:
** my_strtok
*/

#include "my.h"

static int is_delimiter(char c, char const *delim)
{
    for (int i = 0; delim[i] != '\0'; i += 1) {
        if (c == delim[i])
            return OK;
    }
    return ERR;
}

char *my_strtok(char *str, char const *delimiter)
{
    static char *nextToken = NULL;
    char *tokenStart = NULL;

    if (str != NULL) {
        nextToken = str;
    } else if (nextToken == NULL)
        return NULL;
    while (*nextToken != '\0' && is_delimiter(*nextToken, delimiter) == OK)
        nextToken += 1;
    if (*nextToken == '\0')
        return NULL;
    tokenStart = nextToken;
    while (*nextToken != '\0' && is_delimiter(*nextToken, delimiter) != OK)
        nextToken += 1;
    if (*nextToken != '\0') {
        *nextToken = '\0';
        nextToken += 1;
    } else
        nextToken = NULL;
    return tokenStart;
}
