/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** dsk
*/

#include "libmy.h"

int my_count_words(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i + 1] == '\0')
            count++;
    }
    return (count);
}

int my_word_len(char const *str)
{
    int len = 0;

    for (;str[len] != ' ' && str[len] != '\n' && str[len] != '\0'; len++);
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (my_count_words(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; str[i] != '\0'; i++) {
        array[j] = malloc(sizeof(char) * (my_word_len(&str[i]) + 1));
        for (k = 0; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; k++) {
            array[j][k] = str[i];
            i++;
        }
        if (str[i] == '\0')
            break;
        array[j][k] = '\0';
        j++;
    }
    array[j] = NULL;
    return (array);
}
