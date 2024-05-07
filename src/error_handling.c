/*
** EPITECH PROJECT, 2024
** root_for_mt_repo
** File description:
** error_handling
*/

#include "my.h"

static int check_nbr_of_files(int argc, char const *const *argv)
{
    int nb = 0;

    for (int i = 1; i < argc; i++) {
        if (!argv[i])
            return KO;
        if (argv[i][0] == '-') {
            i += 1;
            continue;
        }
        if (argv[i][0] != '-')
            nb += 1;
    }
    if (nb >= 2 && nb <= 3)
        return OK;
    return KO;
}

int error_handling(int argc, char const *const *argv)
{
    if (argc < 3)
        return KO;
    if (!argv || !argv[0])
        return KO;
    if (check_nbr_of_files(argc, argv) == KO)
        return KO;
    return OK;
}
