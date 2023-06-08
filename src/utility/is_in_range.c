/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** is_in_range
*/

#include "../../include/my.h"

int get_distance(int x1, int y1, int x2, int y2)
{
    return (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
