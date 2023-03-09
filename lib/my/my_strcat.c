/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** dsk
*/

#include "libmy.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
