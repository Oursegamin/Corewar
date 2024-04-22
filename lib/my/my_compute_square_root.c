/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int result = 1;
    int temp;
    int max_lim = 46350;

    if (nb <= 0) {
        return (0);
    }
    if (nb == 1) {
        return (1);
    }
    for (int n = 2; n <= max_lim; n += 1) {
        temp = n;
        if (temp * n == nb) {
            return n;
        }
        result = n;
    }
    return (result);
}
