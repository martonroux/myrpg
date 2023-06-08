/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_entity.c
*/

#include "../../../include/my.h"

void create_anim_data(
    entity_t *entity,
    sfIntRect rect,
    collector_t *collector,
    void (*anim_func)(entity_t *, sfIntRect, sfVector2i)
    )
{
    anim_data_t *anim_data = my_malloc(sizeof(anim_data_t), collector);
    sfVector2u texture_size = sfTexture_getSize(entity->texture);
    sfVector2i size = {(int)texture_size.x, (int)texture_size.y};

    sfSprite_setTextureRect(entity->sprite, rect);
    anim_data->anim_rect = rect;
    anim_data->full_size = size;
    anim_data->movement_dir = NONE;
    anim_data->anim_func = anim_func;
    anim_data->state = STATE_NORMAL;
    entity->anim_data = anim_data;
    set_sprite_origin(entity->sprite);
}

entity_t *create_single_entity(
    char *img_path,
    entity_type_t type,
    collector_t *collector,
    void (*update)(entity_t *, game_t *)
    )
{
    entity_t *new = my_malloc(sizeof(entity_t), collector);

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(img_path, NULL);
    new->hp = 10.f;
    new->is_visible = 1;
    new->next = NULL;
    new->prev = NULL;
    new->update = update;
    new->type = type;
    new->speed = 6.f;
    new->chunks = NULL;
    new->weapon = NULL;
    new->anim_data = NULL;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    return new;
}

head_entity_t *create_entity_ll(collector_t *collector)
{
    head_entity_t *new_entity = my_malloc(sizeof(head_entity_t), collector);

    new_entity->first = NULL;
    new_entity->first_blood = NULL;
    return new_entity;
}
