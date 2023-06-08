/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** my_into_str.c
*/

#include "../../../include/my.h"

char *into_str(int nb)
{
    int length = 0;
    int num = nb;
    int i = 0;
    char* str;

    while (num != 0) {
        length++;
        num /= 10;
    }
    str = malloc(sizeof(char) * (length + 1));
    while (nb != 0) {
        str[i++] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    str = my_revstr(str, i);
    return str;
}
