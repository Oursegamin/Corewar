/*
** EPITECH PROJECT, 2023
** Precision
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/mini_printf.h"

static int (*accurate_flag[])(double, int, int) = {
    my_put_scientist,
    my_put_scientist,
    my_put_double,
    my_put_double
};

void accurate(const char *format, double nbr, int precision, int *i)
{
    char const flag[5] = "eEfF";
    int count = 0;
    int maj = 0;

    while (flag[count] != '\0') {
        if (flag[count] == 'E' || flag[count] == 'F') {
            maj = 1;
        } else {
            maj = 0;
        }
        if (flag[count] == format[*i]) {
            accurate_flag[count](nbr, precision, maj);
            *i += 1;
        }
        count += 1;
    }
}

int my_precision(const char *format, double nbr, int precision, int *i)
{
    int tmp = *i;
    int nb = 0;

    precision = 0;
    *i = *i + 2;
    while (format[*i] >= '0' && format[*i] <= '9') {
        nb = format[*i];
        nb = nb - 48;
        if (*i > tmp) {
            precision = precision * 10;
            precision = nb + precision;
        } else
            precision = nb + precision;
        *i += 1;
    }
    accurate(format, nbr, precision, &*i);
    return 0;
}
