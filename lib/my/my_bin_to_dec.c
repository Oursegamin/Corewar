/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** my_bin_to_dec
*/

#include "my.h"

int bin_to_dec(const char *binary)
{
    int decimal = 0;
    int power_of_two = 1;

    for (int i = strlen(binary) - 1; i >= 0; i -= 1) {
        if (binary[i] == '1')
            decimal += power_of_two;
        if (binary[i] != '0' && binary[i] != '1')
            return -KO;
        power_of_two *= 2;
    }
    return decimal;
}
