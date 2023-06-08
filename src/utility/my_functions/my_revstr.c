/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** my_revstr.c
*/

#include "../../../include/my.h"

char *my_revstr(char *str, int i)
{
    char temp;
    for (int j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return str;
}
