/*
** EPITECH PROJECT, 2023
** init_map
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

void init_map_pdeux(my_navy_t *navy, char x)
{
    for (int i = 1; i < navy->size - 1; i++) {
        if (navy->po1 == navy->po2)
            navy->my_map[navy->poi1 + 1 +i][(navy->po2 - 63) + (navy->po2 - 65)]
            = x;
        else
            navy->my_map[navy->poi1 + 1][(navy->po1 - 63) + (navy->po1 - 65) +
            (i * 2)] = x;
    }
}

void init_map_trois(my_navy_t *navy)
{
    if (navy->size == 2) {
        navy->my_map[navy->poi1 + 1][(navy->po1 - 63) + (navy->po1 - 65)] = '2';
        navy->my_map[navy->poi2 + 1][(navy->po2 - 63) + (navy->po2 - 65)] = '2';
    }
    if (navy->size == 3) {
        navy->my_map[navy->poi1 + 1][(navy->po1 - 63) + (navy->po1 - 65)] = '3';
        init_map_pdeux(navy, '3');
        navy->my_map[navy->poi2 + 1][(navy->po2 - 63) + (navy->po2 - 65)] = '3';
    }
    if (navy->size == 4) {
        navy->my_map[navy->poi1 + 1][(navy->po1 - 63) + (navy->po1 - 65)] = '4';
        init_map_pdeux(navy, '4');
        navy->my_map[navy->poi2 + 1][(navy->po2 - 63) + (navy->po2 - 65)] = '4';
    }
    if (navy->size == 5) {
        navy->my_map[navy->poi1 + 1][(navy->po1 - 63) + (navy->po1 - 65)] = '5';
        init_map_pdeux(navy, '5');
        navy->my_map[navy->poi2 + 1][(navy->po2 - 63) + (navy->po2 - 65)] = '5';
    }
}

int init_map(my_navy_t *navy)
{
    for (int o = 0; navy->position_file[o] != '\0'; o++) {
        navy->size = my_atoi(&navy->position_file[o]);
        navy->po1 = navy->position_file[o + 2];
        navy->po2 = navy->position_file[o + 5];
        navy->poi1 = my_atoi(&navy->position_file[o + 3]);
        navy->poi2 = my_atoi(&navy->position_file[o + 6]);
        init_map_trois(navy);
        o = o + 7;
    }
    return 0;
}
