/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** my_strcat.c
*/

#include "../../../include/my.h"

char *my_strcat(char *str, char *targ)
{
    char *end = malloc(sizeof(char) * (my_strlen(str) + my_strlen(targ) + 1));
    int ind = 0;
    for (int i = 0; str[i] != '\0'; i++)
        end[ind++] = str[i];
    for (int i = 0; targ[i] != '\0'; i++) {
        if (targ[i] == '\n')
            break;
        end[ind++] = targ[i];
    }
    end[ind] = '\0';
    return end;
}
