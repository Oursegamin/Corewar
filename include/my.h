/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** task02
*/

#ifndef LIB_H_
    #define LIB_H_

    #include "enum.h"

    #include "op.h"
    #include "corewar.h"
    #include "init_area.h"

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string.h>

    #include "macro.h"
    #include "proto.h"

int my_putchar(char c);
void my_put_errchar(char c);
int my_putstr(char const *str);
int my_put_errstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
char *my_strtok(char *str, char const *delimiter);
char *my_strstr(char const *str, char const *needle);
int my_arraylen(char **array);
char *my_int_to_base(unsigned long nbr, int base);
int bin_to_dec(const char *binary);
int my_compute_power_rec(int nb, int p);
unsigned int my_htonl(int valeur);
unsigned short my_htons(unsigned short valeur);
void my_memcpy(void *dest, const void *src, size_t n);
void my_swap(void *a, void *b, int size_a, int size_b);
uint8_t *my_uint8_ndup(uint8_t const *src, int n);

#endif /* LIB_H_ */
