/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** collisions_zombies.c
*/

#include "../../include/my.h"

int single_bullet_with_zombies(bullet_t *bullet, chunk_t *actual)
{
    sfFloatRect rect;
    sfVector2f pos = bullet->position;

    while (actual) {
        if (actual->entity->type == bullet->shooter_type
            || actual->entity->type == NPC) {
            actual = actual->next;
            continue;
        }
        rect = sfSprite_getGlobalBounds(actual->entity->sprite);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            actual->entity->hp -= (float)bullet->damage;
            actual->entity->anim_data->state = STATE_HURT;
            return 1;
        }
        actual = actual->next;
    }
    return 0;
}

void collisions_bullets_chunk(game_t *game, head_chunk_t *chunk)
{
    bullet_chunk_t *actual_bullet = chunk->first_bullet;
    chunk_t *actual_zombie = chunk->first;

    while (actual_bullet) {
        if (actual_bullet->bullet->is_dead == true) {
            actual_bullet = actual_bullet->next;
            continue;
        }
        if (single_bullet_with_zombies(actual_bullet->bullet, actual_zombie))
            actual_bullet->bullet->is_dead = true;
        actual_bullet = actual_bullet->next;
    }
}

void collisions_bullets_zombies(game_t *game)
{
    head_chunk_t **p_head_chunk = game->head_chunk;

    for (int i = 0; p_head_chunk[i]; i++) {
        collisions_bullets_chunk(game, p_head_chunk[i]);
    }
    collisions_bullets_chunk(game, game->outside_screen);
}
