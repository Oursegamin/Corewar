/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** my_hontl
*/

unsigned short my_htons(unsigned short valeur)
{
    return ((valeur & 0xFF00) >> 8) | ((valeur & 0x00FF) << 8);
}

unsigned int my_htonl(int valeur)
{
    return ((valeur & 0xFF) << 24) |
        (((valeur >> 8) & 0xFF) << 16) |
        (((valeur >> 16) & 0xFF) << 8) |
        ((valeur >> 24) & 0xFF);
}
