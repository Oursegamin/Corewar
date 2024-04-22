/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** task07
*/

int find_prime(int n)
{
    int b;

    for (int a = 2; a < n; a += 1) {
        b = n % a;
        if (b == 0) {
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (find_prime(nb) == 1) {
        return (nb);
    } else {
        my_find_prime_sup(nb + 1);
    }
}
