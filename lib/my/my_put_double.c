/*
** EPITECH PROJECT, 2023
** decimal
** File description:
** printf
*/

#include "../../include/my.h"

static int arround(char *str, int j)
{
    int i = j - 1;

    while (j >= 0 && str[i] == '9') {
        str[i] = '0';
        i -= 1;
        if (str[i] != '9' && str[i] != '.')
            str[i] = str[i] + 1;
        if (str[i] == '.')
            str[i - 1] = str[i - 1] + 1;
    }
    if (j > 0) {
        if (str[j - 1] >= '5' && str[j - 1] < '9') {
            str[i] = '\0';
            str[i - 1] = str[i - 1] + 1;
            return 1;
        }
    }
    str[j - 1] = '\0';
    return 0;
}

void decimal(double nbr, int precision, char *str, int count)
{
    int j;
    int i = my_strlen(str);

    while (i < count) {
        nbr = nbr * 10;
        str[i] = (int) nbr + 48;
        i += 1;
        nbr = nbr - (int) nbr;
    }
    i = i + 1;
    str[i] = '.';
    j = i + precision + 1;
    while (i < j) {
        nbr = nbr * 10;
        str[i] = (int) nbr + 48;
        i += 1;
        nbr = nbr - (int) nbr;
    }
    arround(str, j);
}

int my_put_double(double nbr, int precision, int maj)
{
    char str[1000] = "";
    int count = 0;
    int i = 0;

    if ((int) nbr == 0) {
        i = i + 1;
        str[i] = '0';
    }
    while (nbr >= 1) {
        nbr = nbr / 10;
        count += 1;
        if (count > 308 && maj == 0)
            return my_putstr("inf");
        if (count > 308 && maj == 1)
            return my_putstr("INF");
    }
    decimal(nbr, precision, str, count);
    return my_putstr(str);
}
