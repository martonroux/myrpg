/*
** EPITECH PROJECT, 2023
** mystrlen
** File description:
** rep
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
