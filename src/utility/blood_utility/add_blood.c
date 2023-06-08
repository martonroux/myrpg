/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** add_blood.c
*/

#include "../../../include/my.h"

void add_blood(head_entity_t *head_entity, sfVector2f position,
                saved_sprites_t *saved_sprites)
{
    blood_node_t *blood_node = malloc(sizeof(blood_node_t));
    sfIntRect rect = {0, 0, 700, 400};

    blood_node->sprite = sfSprite_copy(saved_sprites->blood);
    sfSprite_setPosition(blood_node->sprite, position);
    sfSprite_setTextureRect(blood_node->sprite, rect);
    set_sprite_origin(blood_node->sprite);
    blood_node->rect = rect;
    blood_node->is_dead = false;

    blood_node->next = head_entity->first_blood;
    head_entity->first_blood = blood_node;
}
