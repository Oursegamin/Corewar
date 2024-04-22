/*
** EPITECH PROJECT, 2023
** Printf
** File description:
** Projet
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../include/mini_printf.h"
#include "../../include/my.h"

static int (*print_flag[])(char const *, va_list, int *i) = {
    flag_c,
    flag_d,
    flag_i,
    flag_s,
    flag_percent,
    flag_o,
    flag_u,
    flag_x,
    flag_tallx,
    flag_f,
    flag_tallf,
    flag_p,
    flag_e,
    flag_talle,
    flag_precision,
    h_modifier,
    l_modifier
};

int error(int res)
{
    if (res == -1)
        return -84;
    return 1;
}

static int s_flag(char const *format, va_list list, int *i)
{
    int count = 0;
    char const flag[17] = "cdis%ouxXfFpeE.hl";
    int res = 0;

    while (flag[count] != '\0') {
        if (flag[count] == format[*i + 1]) {
            res = print_flag[count](format, list, i);
            return res;
        }
        count += 1;
    }
    res = -1;
    return res;
}

int loop(char const *format, va_list list)
{
    int i = 0;
    int res = 0;
    int c = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            res = s_flag(format, list, &i);
            error(res);
        }
        if (format[i] != '%') {
            my_putchar(format[i]);
            c = c + 1;
        } else {
            i += 1;
        }
        i += 1;
    }
    return c + res;
}

int my_printf(char const *format, ...)
{
    va_list list;
    int len = 0;

    va_start(list, format);
    len = loop(format, list);
    va_end(list);
    return len;
}
