/*
** EPITECH PROJECT, 2023
** Projet-Graphic
** File description:
** main
*/

#include "my.h"

int main(int argc, char const *const *argv)
{
    if (argc == 2 && argv && argv[1] && my_strcmp(argv[1], "-h") == OK)
        return fs_open_file("README.md");
    if (argc == 2 && (my_strlen(argv[1]) > 2 ||
    my_strcmp(&argv[1][my_strlen(argv[1] - 2)], ".s") == OK))
        return launch_facto(argv[1]);
    my_put_errstr("Usage: ./asm filename[.s] ....\n");
    return KO;
}
