/*
** EPITECH PROJECT, 2023
** error
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int error (int i)
{
    if (i == 0)
        my_printf("Error: invalid environnement\n");
    if (i == 1)
        my_printf("Error: invalid argument\n");
    if (i == 2)
        my_printf("Error: invalid pid\n");
    if (i == 3)
        my_printf("Error: invalid file\n");
    if (i == 4) {
        my_printf("wrong position\n");
        return 0;
    }
    return 84;
}

int error_same_position_part_deux(my_navy_t *navy, int i)
{
    for (int o = i + 1; navy->position_file[o] != '\0'; o++) {
        if (navy->position_file[i] == ':' &&
            navy->position_file[i] == navy->position_file[o] &&
            navy->position_file[i + 1] == navy->position_file[o + 1] &&
            navy->position_file[i + 2] == navy->position_file[o + 2]) {
            return error(3);
        }
    }
    return 0;
}

int error_same_position(my_navy_t *navy)
{
    for (int i = 0; navy->position_file[i] != '\0'; i++) {
        if (error_same_position_part_deux(navy, i) == 84)
            return 84;
    }
    return 0;
}

int posboat_player(my_navy_t *navy)
{
    int count = 0, sizemax = 0;
    for (int o = 0; navy->position_file[o] != '\0'; o++) {
        navy->size = my_atoi(&navy->position_file[o]);
        navy->po1 = navy->position_file[o + 2];
        navy->po2 = navy->position_file[o + 5];
        navy->poi1 = my_atoi(&navy->position_file[o + 3]);
        navy->poi2 = my_atoi(&navy->position_file[o + 6]);
        if (navy->size == 6 || navy->size == 1)
            return error(3);
        if (navy->poi1 > 8 || navy->poi2 > 8)
            return error(3);
        if (boat_error(navy) == 84)
            return 84;
        o = o + 7;
        count++;
        sizemax += navy->size;
    }
    if (count != 4 || sizemax != 14)
        return error(3);
    return 0;
}

int error_position_bat(my_navy_t *navy, int i)
{
    navy->position_file = my_open_file(navy->av[i]);
    if (navy->position_file == NULL)
        return error(3);
    if (posboat_player(navy) == 84)
        return 84;
    return 0;
}
