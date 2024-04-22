/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int result;
    int max = 2147483647 / nb;
    int min = -2147483648 / nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (p == 1) {
        return (nb);
    }
    result = my_compute_power_rec(nb, p - 1) * nb;
    if (result > max || result < min) {
        return (0);
    }
    return (result);
}
