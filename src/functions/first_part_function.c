/*
** EPITECH PROJECT, 2023
** function
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int *static_var_o(void)
{
    static int o = 0;
    return &o;
}

int info (void)
{
    my_printf("USAGE\n");
    my_printf("     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("     first_player_pid: only for the 2nd player. pid of the");
    my_printf(" first player.\n");
    my_printf("     navy_positions: file representing the positions of the");
    my_printf(" ships.\n");
    return 0;
}

int verif_pid(char *av)
{
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] < '0' || av[i] > '9')
            return 84;
    }
    return 0;
}

void synchros(int sig, siginfo_t *siginfo, void *context)
{
    int *o = static_var_o();

    context = context;
    if (sig == SIGUSR1) {
    }
    if (sig == SIGUSR2) {
        *o = siginfo->si_pid;
        usleep(100);
        kill(*o, SIGUSR1);
    }
}

char **map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 9; i++)
        map[i] = malloc(sizeof(char) * 18);
    map[0] = my_strdup(" |A B C D E F G H");
    map[1] = my_strdup("-+---------------");
    map[2] = my_strdup("1|. . . . . . . .");
    map[3] = my_strdup("2|. . . . . . . .");
    map[4] = my_strdup("3|. . . . . . . .");
    map[5] = my_strdup("4|. . . . . . . .");
    map[6] = my_strdup("5|. . . . . . . .");
    map[7] = my_strdup("6|. . . . . . . .");
    map[8] = my_strdup("7|. . . . . . . .");
    map[9] = my_strdup("8|. . . . . . . .");
    map[10] = NULL;
    return map;
}
