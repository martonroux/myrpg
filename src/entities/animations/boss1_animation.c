/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** boss1_animation.c
*/

#include "../../../include/my.h"

void resume_animation(entity_t *entity, sfIntRect rect)
{
    sfSprite_setTextureRect(entity->sprite, rect);
    entity->anim_data->anim_rect = rect;
}

void boss1_animation_down(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    if (rect.top == 0) {
        rect.top = rect.height * 2;
        rect.left = rect.width * 2;
        resume_animation(entity, rect);
        return;
    }
    if (rect.top == rect.height) {
        rect.top = rect.height * 2;
        rect.left = rect.width;
        resume_animation(entity, rect);
        return;
    }
    rect.top = rect.height * 2;
    rect.left += rect.width;
    if (rect.left < rect.width * 4)
        rect.left = rect.width * 4;
    if (rect.left > size.x - rect.width)
        rect.left = rect.width * 4;
    resume_animation(entity, rect);
}

void boss1_animation_right(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    if (rect.top == rect.height * 2 && rect.left >= rect.width * 4) {
        rect.left = rect.width * 2;
        resume_animation(entity, rect);
        return;
    }
    rect.top = 0;
    rect.left += rect.width;
    if (rect.left > size.x - rect.width)
        rect.left = 0;
    resume_animation(entity, rect);
}

void boss1_animation_left(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    if (rect.top == rect.height * 2 && rect.left >= rect.width * 4) {
        rect.left = rect.width;
        resume_animation(entity, rect);
        return;
    }
    rect.top = rect.height;
    rect.left += rect.width;
    if (rect.left > size.x - rect.width)
        rect.left = 0;
    resume_animation(entity, rect);
}

void boss1_animation(entity_t *entity, sfIntRect rect, sfVector2i size)
{
    movement_dir_t dir = entity->anim_data->movement_dir;

    if (dir == DOWN) {
        boss1_animation_down(entity, rect, size);
    }
    if (dir == RIGHT) {
        boss1_animation_right(entity, rect, size);
    }
    if (dir == LEFT) {
        boss1_animation_left(entity, rect, size);
    }
}
