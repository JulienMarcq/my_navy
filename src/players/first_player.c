/*
** EPITECH PROJECT, 2023
** first_player
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int first_player_part_deux(my_navy_t *navy)
{
    navy->ordre = 1;
    while (1) {
        if (attack(navy->pid, navy) == 1)
            return 0;
        if (receiver(navy, 0, navy->pid) == 1)
            return 0;
    }
    return 0;
}

void first_player(my_navy_t *navy)
{
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = synchros;
    sigaction(SIGUSR2, &sa, 0);
    pause();
    navy->pid = *static_var_o();
    my_printf("\nenemy connected\n");
    navy->my_map = map();
    navy->ennemy_map = map();
    init_map(navy);
    my_printf("\nmy positions:\n");
    my_print_array(navy->my_map);
    my_printf("\nenemy's positions:\n");
    my_print_array(navy->ennemy_map);
    my_printf("\n");
    navy->ennemy_boat = 14;
    navy->my_boat = 14;
    first_player_part_deux(navy);
}
