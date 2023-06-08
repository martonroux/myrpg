/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** int_to_str
*/

#include "../../include/my.h"

char *int_to_str(int nb)
{
    int i = 0;
    int nb2 = nb;
    char *str = NULL;
    if (nb == 0)
        return "0";
    while (nb2 > 0) {
        nb2 /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    str[i] = 0;
    while (i > 0) {
        str[i - 1] = (nb % 10) + '0';
        nb /= 10;
        i--;
    }
    return str;
}
