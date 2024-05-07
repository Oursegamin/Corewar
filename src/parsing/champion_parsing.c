/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** champion_parsing
*/

#include "my.h"

// for (int i = 0; i < (*champions)->prog_size; i++)
//     printf("%x ", ((char *)(*champions)->instructions)[i]);
// printf("\n");

char *read_champion(char const *filepath)
{
    FILE *file = NULL;
    char *buffer = NULL;
    struct stat st;

    lstat(filepath, &st);
    if (st.st_size < (__off_t)(sizeof(header_t) + 1))
        return NULL;
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    file = fopen(filepath, "r");
    if (fread(buffer, sizeof(char), st.st_size, file) != (size_t)st.st_size) {
        fclose(file);
        free(buffer);
        return NULL;
    }
    buffer[st.st_size] = '\0';
    fclose(file);
    return buffer;
}

int parse_champion_header(champion_t **champions, char **filepath)
{
    __uint32_t *tmp = (__uint32_t *)my_strndup(*filepath, 4);

    *tmp = my_htonl(*tmp);
    if (*tmp != COREWAR_EXEC_MAGIC)
        return KO;
    (*champions)->prog_name = my_strdup(&(*filepath)[4]);
    if (!tmp)
        return KO;
    tmp = (__uint32_t *)my_strndup(&(*filepath)[8 + PROG_NAME_LENGTH], 4);
    if (!tmp)
        return KO;
    (*champions)->prog_size = my_htonl(*tmp);
    *filepath = *filepath + sizeof(header_t);
    return OK;
}

int parse_champion_body(champion_t **champions, char **filepath)
{
    (*champions)->instructions = (__uint8_t *)my_strndup(*filepath,
        (*champions)->prog_size);
    if (!(*champions)->instructions)
        return KO;
    return OK;
}

int parse_champion(champion_t **champions, char const *filepath)
{
    char *file = NULL;

    if (!*champions || !filepath)
        return KO;
    file = read_champion(filepath);
    if (!file)
        return KO;
    if (parse_champion_header(champions, &file) == KO)
        return KO;
    if (parse_champion_body(champions, &file) == KO)
        return KO;
    return OK;
}
