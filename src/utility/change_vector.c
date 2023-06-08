/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** change_vector
*/

#include "../../include/my.h"

sfVector2i change_vectori(sfVector2f vector)
{
    sfVector2i new_vector = {vector.x, vector.y};
    return new_vector;
}

sfVector2f change_vectorf(sfVector2i vector)
{
    sfVector2f new_vector = {(float)vector.x, (float)vector.y};
    return new_vector;
}
