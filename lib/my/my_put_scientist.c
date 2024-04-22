/*
** EPITECH PROJECT, 2023
** scientist print
** File description:
** printf
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

char *integer(double *nbr, int i, char *str, int *expo)
{
    while (*nbr >= 0 && *nbr < 1) {
        *nbr = *nbr * 10;
        *expo += 1;
    }
    while (*nbr >= 1) {
        *nbr = *nbr / 10;
        *expo += 1;
    }
    while (*nbr >= 0 && *nbr < 10) {
        if (*nbr >= 1) {
            str[i] = (int) *nbr + 48;
            i += 1;
        }
        *nbr = *nbr * 10;
    }
    if (*nbr >= 10)
        *nbr = *nbr / 10;
    return str;
}

static int arround(char *str, int j)
{
    int i = j - 1;

    while (j > 0 && str[i - 1] == '9') {
        str[i] = '0';
        i -= 1;
        if (str[i] != '9')
            str[i] = str[i] + 1;
    }
    if (j > 0) {
        if (str[j - 1] >= '5' && str[j - 1] <= '9') {
            str[i - 1] = str[i - 1] + 1;
            str[i] = '\0';
            return 1;
        }
    }
    str[j - 1] = '\0';
    return 0;
}

char *decimal_nbr(double nbr, int precision, char *str)
{
    int i = my_strlen(str);
    int j;

    i = i + 1;
    str[i] = '.';
    j = i + precision + 1;
    while (i < j) {
        nbr = nbr - (int) nbr;
        nbr = nbr * 10;
        str[i] = (int) nbr + 48;
        i += 1;
    }
    arround(str, j);
    return str;
}

void print_char(char *str, double sign, int i, int maj)
{
    if (maj == 0) {
        i = i + 1;
        str[i] = 'e';
    } else {
        i = i + 1;
        str[i] = 'E';
    }
    if ((int) sign >= 1) {
        i = i + 1;
        str[i] = '+';
    } else {
        i = i + 1;
        str[i] = '-';
    }
}

char *exponent(char *str, double sign, int *expo, int maj)
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = '\0';
        i += 1;
    }
    i = 0;
    print_char(str, sign, i, maj);
    *expo = *expo - 1;
    if (*expo <= 9) {
        i = i + 1;
        str[i] = '0';
    }
    return str;
}

int my_put_scientist(double nbr, int precision, int maj)
{
    char str[1000] = "";
    int expo = 0;
    int i = 0;
    double sign = nbr;
    int len;

    if (nbr < 0) {
        nbr = nbr * -1;
        sign = sign * -1;
        my_putchar('-');
    }
    integer(&nbr, i, str, &expo);
    len = my_putstr(decimal_nbr(nbr, precision, str));
    len += my_putstr(exponent(str, sign, &expo, maj));
    return (len + my_put_nbr(expo));
}
