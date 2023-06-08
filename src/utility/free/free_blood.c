/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** free_blood.c
*/

#include "../../../include/my.h"

void free_blood(blood_node_t *blood_node)
{
    sfSprite_destroy(blood_node->sprite);
}
