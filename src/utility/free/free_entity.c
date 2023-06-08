/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** free_entity.c
*/

#include "../../../include/my.h"

void free_entity(entity_t *entity)
{
    free(entity->anim_data);
    if (entity->weapon) {
        free(entity->weapon);
    }
    free(entity->chunks);
}
