/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** my_get_nbr
*/

#include "../../include/my.h"

int my_get_nbr(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str == NULL)
        return 0;
    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10 + (str[i] - '0');
    }
    return nb * neg;
}
