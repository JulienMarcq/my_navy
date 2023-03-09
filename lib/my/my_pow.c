/*
** EPITECH PROJECT, 2022
** my_pow
** File description:
** dsk
*/

#include "libmy.h"

int my_pow(int nb, int p)
{
    int i = 0;
    int result = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (; i < p; i++)
        result = result * nb;
    return (result);
}
