/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-COREWAR-florian.labadie
** File description:
** COREWAR
*/

#ifndef COREWAR_F_H_
    #define COREWAR_F_H_

    #include <stdint.h>

typedef struct champion_s {
    char *prog_name;
    int prog_size;
    __uint8_t *instructions;

    int PC;

    int nbr_cycle;
    int prog_number;
    int load_address;

    char carry;
} champion_t;

typedef struct corewar_s {
    __uint8_t memory[MEM_SIZE];

    champion_t **champions;
} corewar_t;

#endif /* COREWAR_F_H_ */
