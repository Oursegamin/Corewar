/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-COREWAR-florian.labadie
** File description:
** COREWAR
*/

#ifndef COREWAR_F_H_
    #define COREWAR_F_H_

    #include <stdbool.h>
    #include <stdint.h>

typedef struct champion_s {
    bool is_alive;

    char *prog_name;
    int prog_size;
    __uint8_t *instructions;

    int PC;
    int regs[REG_NUMBER];

    int nbr_cycle;
    int prog_number;

    bool carry;
} champion_t;

typedef struct corewar_s {
    __uint8_t arena[MEM_SIZE];

    int dump;
    int champs_nbr;

    champion_t **champions;
} corewar_t;

#endif /* COREWAR_F_H_ */
