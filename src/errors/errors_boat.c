/*
** EPITECH PROJECT, 2023
** second_error
** File description:
** dsk
*/

#include "libmy.h"
#include "navy.h"

int boat_2(my_navy_t *navy)
{
    if (navy->po1 == navy->po2) {
        if (navy->poi1 + 1 != navy->poi2)
            return error(3);
    } else {
        if (navy->poi1 != navy->poi2)
            return error(3);
        if ((navy->po1 - 65) + 1 != (navy->po2 - 65))
            return error(3);
    }
    return 0;
}

int boat_3(my_navy_t *navy)
{
    if (navy->po1 == navy->po2) {
        if (navy->poi1 + 2 != navy->poi2)
                return error(3);
    } else {
        if (navy->poi1 != navy->poi2)
            return error(3);
        if ((navy->po1 - 65) + 2 != (navy->po2 - 65))
            return error(3);
    }
    return 0;
}

int boat_4(my_navy_t *navy)
{
    if (navy->po1 == navy->po2) {
        if (navy->poi1 + 3 != navy->poi2)
            return error(3);
    } else {
        if (navy->poi1 != navy->poi2)
            return error(3);
        if ((navy->po1 - 65) + 3 != (navy->po2 - 65))
            return error(3);
    }
    return 0;
}

int boat_5(my_navy_t *navy)
{
    if (navy->po1 == navy->po2) {
        if (navy->poi1 + 4 != navy->poi2)
            return error(3);
    } else {
        if (navy->poi1 != navy->poi2)
            return error(3);
        if ((navy->po1 - 65) + 4 != (navy->po2 - 65))
            return error(3);
    }
    return 0;
}

int boat_error(my_navy_t *navy)
{
    if (navy->size == 2) {
        if (boat_2(navy) == 84)
            return 84;
    }
    if (navy->size == 3) {
        if (boat_3(navy) == 84)
            return 84;
    }
    if (navy->size == 4) {
        if (boat_4(navy) == 84)
            return 84;
    }
    if (navy->size == 5) {
        if (boat_5(navy) == 84)
            return 84;
    }
    return 0;
}
