/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Task02
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len += 1;
    }
    return (len);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int j = my_strlen(dest);
    int a = 0;

    while (a != nb) {
        dest[j] = src[a];
        j += 1;
        a += 1;
    }
    return (dest);
}
