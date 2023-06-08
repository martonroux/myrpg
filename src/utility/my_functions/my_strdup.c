/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** my_strdup.c
*/

#include "../../../include/my.h"

entity_t *my_entitydup(entity_t *to_dup, collector_t *collector)
{
    entity_t *new_entity = my_malloc(sizeof(entity_t), collector);

    new_entity->position = to_dup->position;
    new_entity->sprite = to_dup->sprite;
    new_entity->anim_data = to_dup->anim_data;
    new_entity->type = to_dup->type;
    new_entity->hp = to_dup->hp;
    new_entity->weapon = to_dup->weapon;
    new_entity->speed = to_dup->speed;
    new_entity->texture = to_dup->texture;
    new_entity->update = to_dup->update;
    new_entity->is_visible = to_dup->is_visible;
    new_entity->collider = to_dup->collider;

    return new_entity;
}

char *my_strdup(const char *str, collector_t *collector)
{
    if (str == NULL)
        return NULL;
    char *new_ptr = my_malloc(sizeof(str), collector);

    return new_ptr;
}
