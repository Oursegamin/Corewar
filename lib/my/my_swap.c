/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** task01
*/

int my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
