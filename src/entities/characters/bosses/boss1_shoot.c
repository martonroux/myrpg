/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** boss1_shoot.c
*/

#include "../../../../include/my.h"

bullet_t *create_bullet_boss1(game_t *game, entity_t *entity,
                                sfVector2f pos, sfVector2f play)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    double angle;

    bullet->sprite = sfSprite_copy(entity->weapon->sprite_bullet);
    bullet->position = pos;
    bullet->direction = get_direction_toward(bullet->sprite, pos, play);
    sfSprite_setTextureRect(bullet->sprite, (sfIntRect){0, 0, 64, 32});
    set_sprite_origin(bullet->sprite);
    angle = sfSprite_getRotation(bullet->sprite);
    sfSprite_setRotation(bullet->sprite, angle - 90);
    sfSprite_setPosition(bullet->sprite, bullet->position);
    bullet->next = NULL;
    bullet->stat = game->stat;
    bullet->damage = entity->weapon->damage;
    bullet->is_visible = true;
    bullet->is_dead = false;
    bullet->shooter_type = BOSS;
    bullet->speed = 15;
    bullet->range = 2000;
    return bullet;
}

void boss1_shoot(game_t *game, entity_t *entity)
{
    sfClock *clock = entity->weapon->shoot_clock;
    sfTime time = sfClock_getElapsedTime(clock);
    bullet_t *bullet;
    sfVector2f play = get_player_entity(game)->position;
    sfVector2f pos = entity->position;
    float seconds = (float)time.microseconds / 1000000.0f;

    if (seconds < entity->weapon->shoot_rate)
        return;
    sfClock_restart(clock);
    bullet = create_bullet_boss1(game, entity, pos, play);
    add_bullet_to_list(bullet, entity->weapon->head_bullet);
}
