/*
** EPITECH PROJECT, 2022
** my_print_array
** File description:
** dsk
*/

#include "libmy.h"

void my_print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
