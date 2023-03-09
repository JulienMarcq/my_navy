/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int my_navy(my_navy_t *navy)
{
    if (navy->ac == 2) {
        if (error_position_bat(navy, 1) == 84)
            return 84;
        if (error_same_position(navy) == 84)
            return 84;
        first_player(navy);
    }
    if (navy->ac == 3) {
        if (error_position_bat(navy, 2) == 84)
            return 84;
        if (error_same_position(navy) == 84)
            return 84;
        if (verif_pid(navy->av[1]) == 84)
            return error(2);
        if (second_player(navy) == 84)
            return 84;
    }
    free(navy->position_file);
    return 0;
}

int main(int ac, char **av, char **env)
{
    my_navy_t navy;
    if (env[0] == NULL)
        return error(0);
    if (ac == 1 || ac > 3)
        return error(1);
    if (my_strcmp(av[1], "-h") == 0)
        return info();
    navy.ac = ac;
    navy.av = av;
    if (my_navy(&navy) == 84)
        return 84;
    return 0;
}
