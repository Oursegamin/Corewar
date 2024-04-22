/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** Robot_F
*/

#ifndef ROBOT_F_H_
    #define ROBOT_F_H_

    #include "my.h"
    #include <stdio.h>

    #define LIVE 1
    #define ZJMP 9
    #define FORK 12
    #define LFORK 15
    #define AND 6
    #define OR 7
    #define XOR 8
    #define REG "01"
    #define DIR "10"
    #define IND "11"
    #define END "00"

typedef struct label_s {
    char *label;
    int nb_bytes;
} label_t;

typedef struct body_s {
    char code;
    char binary;
    char **param;
    short *types;
    int *convert;
    label_t *labels;
} body_t;

typedef struct robot_s {
    header_t *header;
    body_t **body;
} robot_t;

int fs_open_file(const char *file);
int launch_facto(char const *file);
int write_file_cor(char const *cor, header_t *hearder, body_t **body);
int pars_body_data(char *line, body_t ***body);
int get_types(body_t ***body);
int pars_header_data(char *line, header_t **header);
header_t *create_header(void);
char *create_cor(char const *file);
int get_types(body_t ***body);
int parse(FILE *file, robot_t *robot);
void check_commentary(char **line);
int convert_params(body_t ***body, int i);
int check_type(short *types, int len, short type);

#endif /* ROBOT_F_H_ */
