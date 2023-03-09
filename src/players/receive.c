/*
** EPITECH PROJECT, 2023
** receive
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

void confirm_x(int signum)
{
    signum = signum;
    signal(SIGUSR1, get_y);
    signal(SIGUSR2, confirm_y);
}

void reciever(void)
{
    int *o = static_var_o();
    *o = 0;
    signal(SIGUSR1, get_x);
    signal(SIGUSR2, confirm_x);
    while (*o != 1) {}
}

int receiver_part_deux(my_navy_t *navy, int *o, int *x, int *y)
{
    if (navy->ordre == 1)
        print_all_maps(navy);
    *o = 0;
    *x = 0;
    *y = 0;
    if (navy->my_boat == 0) {
        print_all_maps(navy);
        my_printf("\nEnemy won\n");
        return 1;
    }
    return 0;
}

int receiver(my_navy_t *navy, int pe, int pid)
{
    int *x = static_var_x();
    int *y = static_var_y();
    int *o = static_var_o();
    my_printf("waiting for enemy's attack...\n");
    reciever();
    if (navy->my_map[*x + 1][*y - pe] != '.') {
        kill (pid, SIGUSR1);
        navy->my_map[*x + 1][*y - pe] = 'x';
        navy->my_boat -= 1;
        my_printf("%c%d: hit\n\n", (*y / 2) + 64, *x);
    } else {
        kill (pid, SIGUSR2);
        navy->my_map[*x + 1][*y] = 'o';
        my_printf("%c%d: missed\n\n", (*y / 2) + 64, *x);
    }
    if (receiver_part_deux(navy, o, x, y) == 1)
        return 1;
    return 0;
}
