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
int organized_champions(champion_t ***champions, int champs_nbr);
void sort_champions(champion_t ***champions);
int load_in_arena(corewar_t *corewar);

// INSTRUCTIONS
instruct_types_t *get_instruct_types(uint8_t coding_byte);
void live(corewar_t *corewar, champion_t **champion, int prog_nbr);
void zjmp(corewar_t *corewar, champion_t **champion, int prog_nbr);
void fork_i(corewar_t *corewar, champion_t **champion, int prog_nbrr);
void lfork(corewar_t *corewar, champion_t **champion, int prog_nbr);
void ld_i(corewar_t *corewar, champion_t **champion, int prog_nbr);
void lld(corewar_t *corewar, champion_t **champion, int prog_nbr);
void ldi(corewar_t *corewar, champion_t **champion, int prog_nbr);
void lldi(corewar_t *corewar, champion_t **champion, int prog_nbr);
void and_i(corewar_t *corewar, champion_t **champion, int prog_nbr);
void or_i(corewar_t *corewar, champion_t **champion, int prog_nbr);
void xor_i(corewar_t *corewar, champion_t **champion, int prog_nbr);
void add(corewar_t *corewar, champion_t **champion, int prog_nbr);
void sub(corewar_t *corewar, champion_t **champion, int prog_nbr);
void st_i(corewar_t *corewar, champion_t **champion, int prog_nbr);
void sti(corewar_t *corewar, champion_t **champion, int prog_nbr);
void aff(corewar_t *corewar, champion_t **champion, int prog_nbr);

// INSTRUCTIONS PARSING
int *parse_parameter(corewar_t *corewar, instruct_types_t *types,
    instructions_t instruct, champion_t **champion)

#endif /* !PROTO_H_ */
