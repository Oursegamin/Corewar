/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

int error_handling(int argc, char const *const *argv);

int fs_open_file(const char *file);
int launch_war(int argc, char const *const *argv);
int parse_war_progs(corewar_t *corewar, int argc, char const *const *argv);
int parse_champion(champion_t **champions, char const *filepath);
int load_in_arena(corewar_t *corewar);

// INSTRUCTIONS
instruct_types_t *get_instruct_types(uint8_t coding_byte);
void live(corewar_t *corewar);
void zjmp(corewar_t *corewar);
void fork_i(corewar_t *corewar);
void lfork(corewar_t *corewar);
void ld(corewar_t *corewar);
void lld(corewar_t *corewar);
void ldi(corewar_t *corewar);
void lldi(corewar_t *corewar);
void and_i(corewar_t *corewar);
void or_i(corewar_t *corewar);
void xor_i(corewar_t *corewar);
void add(corewar_t *corewar);
void sub(corewar_t *corewar);
void st(corewar_t *corewar);
void sti(corewar_t *corewar);
void aff(corewar_t *corewar);

#endif /* !PROTO_H_ */
