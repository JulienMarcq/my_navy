/*
** EPITECH PROJECT, 2023
** second_player
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int second_player_part_deux(my_navy_t *navy)
{
    my_print_array(navy->ennemy_map);
    my_printf("\n");
    navy->ennemy_boat = 14;
    navy->my_boat = 14;
    navy->ordre = 2;
    while (1) {
        if (receiver(navy, 0, navy->pid) == 1)
            return 0;
        if (attack(navy->pid, navy) == 1)
            return 0;
    }
    return 0;
}

int second_player(my_navy_t *navy)
{
    navy->pid = my_getnbr(navy->av[1]);
    if (kill(navy->pid, SIGUSR2) == -1)
        return error(2);
    my_printf("my_pid: %d\n", getpid());
    usleep(42);
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = synchros;
    sigaction(SIGUSR1, &sa, 0);
    pause();
    my_printf("successfully connected\n");
    navy->my_map = map();
    navy->ennemy_map = map();
    init_map(navy);
    my_printf("\nmy positions:\n");
    my_print_array(navy->my_map);
    my_printf("\nenemy's positions:\n");
    second_player_part_deux(navy);
    return 0;
}
