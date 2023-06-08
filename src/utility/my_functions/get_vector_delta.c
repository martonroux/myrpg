/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** get_vector_delta.c
*/

#include "../../../include/my.h"

double get_vector_delta(sfVector2f vector1, sfVector2f vector2)
{
    float delta_x;
    float delta_y;
    double delta_tot;

    delta_x = vector2.x - vector1.x;
    delta_y = vector2.y - vector1.y;
    delta_tot = sqrt(pow(delta_x, 2) + pow(delta_y, 2));

    return delta_tot;
}
