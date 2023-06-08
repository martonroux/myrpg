/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** players_animation.c
*/

#include "../../../include/my.h"

void zombie_animation(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    entity_state_t state = entity->anim_data->state;

    if (entity->anim_data->movement_dir == UP)
        rect.top = ((state == STATE_HURT) ? rect.height * 4 : 0);
    if (entity->anim_data->movement_dir == LEFT)
        rect.top = rect.height + ((state == STATE_HURT) ? rect.height * 4 : 0);
    if (entity->anim_data->movement_dir == DOWN)
        rect.top = rect.height * 2 +
                ((state == STATE_HURT) ? rect.height * 4 : 0);
    if (entity->anim_data->movement_dir == RIGHT)
        rect.top = rect.height * 3 +
                ((state == STATE_HURT) ? rect.height * 4 : 0);
    rect.left += rect.width;
    if (rect.left > size.x - rect.width)
        rect.left = rect.width;
    if (entity->anim_data->movement_dir == NONE)
        rect.left = 0;

    entity->anim_data->anim_rect = rect;
    sfSprite_setTextureRect(entity->sprite, rect);
}

void player_animation(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    if (entity->anim_data->movement_dir == UP)
        rect.top = 0;
    if (entity->anim_data->movement_dir == LEFT)
        rect.top = rect.height;
    if (entity->anim_data->movement_dir == DOWN)
        rect.top = rect.height * 2;
    if (entity->anim_data->movement_dir == RIGHT)
        rect.top = rect.height * 3;
    rect.left += rect.width;
    if (rect.left > size.x - rect.width)
        rect.left = rect.width;

    if (entity->anim_data->movement_dir == NONE)
        rect.left = 0;

    entity->anim_data->anim_rect = rect;
    sfSprite_setTextureRect(entity->sprite, rect);
}

void npc_animation(entity_t *entity, sfIntRect rect, sfVector2i size)
{
}
