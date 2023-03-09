/*
** EPITECH PROJECT, 2023
** declare
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int *static_var_x(void)
{
    static int x = 0;
    return &x;
}

int *static_var_y(void)
{
    static int y = 0;
    return &y;
}

void get_y(int signal)
{
    int *y = static_var_y();
    signal = signal;
    *y += 1;
}

void get_x(int signal)
{
    int *x = static_var_x();
    signal = signal;
    *x += 1;
}

void confirm_y(int signal)
{
    int *o = static_var_o();
    signal = signal;
    *o = 1;
}
