/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** init_area
*/

#ifndef INIT_AREA_H_
    #define INIT_AREA_H_

typedef struct init_area_s {
    int padding;
    int current_address;
    int next_address;
    bool check_space;
} init_area_t;

#endif /* !INIT_AREA_H_ */
