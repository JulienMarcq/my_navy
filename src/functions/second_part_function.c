/*
** EPITECH PROJECT, 2023
** second_part_function
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;

    for (i = 0; read(fd, &str[i], 1) != 0; i++) {
        if (str[i] == '\n')
            break;
    }
    str[i] = '\0';
    if (i != 2) {
        free(str);
        return (NULL);
    }
    if (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8') {
        free(str);
        return (NULL);
    }
    return (str);
}

int print_all_maps(my_navy_t *navy)
{
    my_printf("my positions:\n");
    my_print_array(navy->my_map);
    my_printf("\nenemy's positions:\n");
    my_print_array(navy->ennemy_map);
    my_printf("\n");
    return 0;
}
