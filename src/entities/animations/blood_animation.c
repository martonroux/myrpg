/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** blood_animation.c
*/

#include "../../../include/my.h"

void blood_animation(blood_node_t *blood_node)
{
    sfIntRect rect = blood_node->rect;

    rect.left += rect.width;
    if (rect.width >= 7000 - rect.width)
        blood_node->is_dead = true;
    blood_node->rect = rect;
    sfSprite_setTextureRect(blood_node->sprite, rect);
}
