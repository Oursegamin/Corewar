/*
** EPITECH PROJECT, 2023
** Projet-Graphic
** File description:
** main
*/

#include "my.h"

int main(int argc, char const *const *argv)
{
    if (error_handling(argc, argv) == KO) {
        my_put_errstr("Usage: ./corewar [-dump nbr_cycle] ");
        my_put_errstr("[[-n prog_number] [-a load_address] prog_name] ...\n");
        return KO;
    }
    if (argc == 2 && argv && argv[1] && my_strcmp(argv[1], "-h") == OK)
        return fs_open_file("README.md");
    if (launch_war(argc, argv) == KO)
        return KO;
    return OK;
}
