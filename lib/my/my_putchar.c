/*
** EPITECH PROJECT, 2023
** myputchar
** File description:
** letsgo
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
