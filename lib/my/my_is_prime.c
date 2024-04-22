/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int b;

    for (int a = 2; a < nb; a += 1) {
        b = nb % a;
        if (b == 0) {
            return (0);
        }
    }
    return (1);
}
