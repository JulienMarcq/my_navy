/*
** EPITECH PROJECT, 2023
** attack
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

void send_coords(int pid, int x, int y)
{
    for (int i = 0; i < x; i++) {
        kill(pid, SIGUSR1);
        usleep(42);
    }
    kill(pid, SIGUSR2);
    usleep(42);
    for (int i = 0; i < y; i++) {
        kill(pid, SIGUSR1);
        usleep(42);
    }
    kill(pid, SIGUSR2);
}

void handler(int signal)
{
    int *o = static_var_o();
    if (signal == SIGUSR1) {
        *o = 1;
    } else if (signal == SIGUSR2) {
        *o = 0;
    }
}

int attack_part_deux( my_navy_t *navy, int *o, int x, int y)
{
    usleep(42);
    if (*o == 1) {
        navy->ennemy_map[x + 1][y] = 'x';
        my_printf("%s: hit\n\n", navy->str);
        navy->ennemy_boat -= 1;
    } else {
        navy->ennemy_map[x + 1][y] = 'o';
        my_printf("%s: missed\n\n", navy->str);
    }
    if (navy->ordre == 2)
        print_all_maps(navy);
    free(navy->str);
    if (navy->ennemy_boat == 0) {
        print_all_maps(navy);
        my_printf("\nI won\n");
        return 1;
    }
    return 0;
}

int attack(int pid, my_navy_t *navy)
{
    int *o = static_var_o();
    *o = 0;
    my_printf("attack:");
    navy->str = get_next_line(0);
    if (navy->str == NULL) {
        error (4);
        attack(pid, navy);
        return 0;
    } int x = my_getnbr(&navy->str[1]);
    int y = (navy->str[0] - 63) + (navy->str[0] - 65);
    if (navy->ennemy_map[x + 1][y] == 'x' || navy->ennemy_map[x + 1][y] == 'o'){
        my_printf("wrong position\n");
        attack(pid, navy);
        return 0;
    } send_coords(pid, x, y);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    if (attack_part_deux(navy, o, x, y) == 1)
        return 1;
    return 0;
}
